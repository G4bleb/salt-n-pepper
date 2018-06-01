<?php
/* CLASSE User */

class User{
  private $id_user;
  private $login;
  private $password;
  private $best_score;
  private $id_game;

  public function getLogin(){
    return $this->login;
  }
  public function getBest_score(){
    return $this->best_score;
  }
  public function setBest_score($setBest_score)
  {
    $this->best_score = $setBest_score;
  }
}

/* CLASSE Game */

class Game{
  private $id_game;
  public function getId(){
    return $this->id_game;
  }
}

/* CLASSE Theme */

class Theme{
  private $id_theme;
  private $theme_name;
}

/* CLASSE Question */

class Question{
  private $id_question;
  private $main_question;
  private $answer1;
  private $answer2;
  private $id_theme;
}

/* CLASSE Proposition */

class Proposition{
  private $id_proposition;
  private $question;
  private $answer_nb;
  private $id_question;
}
?>
