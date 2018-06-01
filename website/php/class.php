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

  public function getTheme_name(){
    return $this->theme_name;
  }
}

/* CLASSE Question */

class Question{
  private $id_theme;
  private $id_question;
  private $main_question;
  private $answer1;
  private $answer2;

  public function getMain_question(){
    return $this->main_question;
  }
  public function getAnswer1(){
    return $this->answer1;
  }
  public function getAnswer12(){
    return $this->answer2;
  }
}

/* CLASSE Proposition */

class Proposition{
  private $id_theme;
  private $id_question;
  private $id_proposition;
  private $main_proposition;
  private $answer_nb;

  public function getMain_proposition(){
    return $this->main_proposition;
  }
}
?>
