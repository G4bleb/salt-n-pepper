<?php

  require_once 'dbconnect.php';

  function addUser($db, $login, $password){
    try{
      $statement = $db->prepare("INSERT INTO user (login, password) VALUES (':login', sha2(':password', 256))");
      $statement->execute(array(':login'=>$login, ':password'=>$password));
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
    return true;
  }
 ?>
