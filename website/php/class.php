<?php
/* CLASSE User */

class User{
  private $id_user;
  private $login;
  private $password;
  private $best_score;
  private $id_game;
  private $token;

  public function getId()  {
    return $this->id_user;
  }
  public function getLogin(){
    return $this->login;
  }
  public function getBestScore(){
    return $this->best_score;
  }
  public function getBestGameId(){
    return $this->id_game;
  }
}

/* CLASSE Game */

class Game{
  private $id_game;

  public function getId(){
    return $this->id_game;
  }
  public function setId($newId){
    $this->id_game = $newId;
  }
  public function loadQuestions($db){
    try{
      $statement = $db->prepare(
        'SELECT
        q.*
        FROM
        `question` AS q,
        `game_question` AS g
        WHERE
        q.`enabled` = 1 AND g.`id_game` = :id_game AND g.`id_topic` = q.`id_topic` AND g.`num_question` = q.`num_question`'
      );
      $statement->execute(array(':id_game'=>$this->id_game));
      $data = $statement->fetchAll(PDO::FETCH_ASSOC);//We're using FETCH_ASSOC and not FETCH_CLASS, 'Question' because we have to json_encode($data)
      // var_dump_in_error_log($data);
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
    return $data;
  }
}

/* CLASSE Topic */

class Topic{
  private $id_topic;
  private $topic_name;

  public function getTopic_name(){
    return $this->topic_name;
  }
}

/* CLASSE Question */

class Question{
  private $id_topic;
  private $num_question;
  private $main_question;
  private $answer1;
  private $answer2;

  public function getMain_question(){
    return $this->main_question;
  }
  public function getAnswer1(){
    return $this->answer1;
  }
  public function getAnswer2(){
    return $this->answer2;
  }
  public function setId_topic($newId_topic){
    $this->id_topic = $newId_topic;
  }
  public function setNum_question($newNum_question){
    $this->num_question = $newNum_question;
  }
  public function loadPropositions($db){
    try{
      $statement = $db->prepare(
        'SELECT
        `num_proposition`,
        `main_proposition`,
        `answer_nb`
        FROM
        `proposition`
        WHERE
        `enabled` = 1 AND `id_topic` = :id_topic AND `num_question` = :num_question'
      );
      $statement->execute(array(':id_topic'=>$this->id_topic, ':num_question'=>$this->num_question));
      $data = $statement->fetchAll(PDO::FETCH_ASSOC);//We're using FETCH_ASSOC and not FETCH_CLASS, 'Proposition' because we have to json_encode($data)
      var_dump_in_error_log($data);
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
    return $data;
  }
}

/* CLASSE Proposition */

class Proposition{
  private $id_topic;
  private $num_question;
  private $num_proposition;
  private $main_proposition;
  private $answer_nb;

  public function getMain_proposition(){
    return $this->main_proposition;
  }
}
?>
