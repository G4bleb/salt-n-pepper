<?php

  require_once 'dbconnect.php';

  function loginExists($db, $login){
    try{
      $statement = $db->prepare("SELECT id_user FROM user WHERE login=:login");
      if (!$statement->execute(array(':login'=>$login))) {
        error_log("loginExists FAILED");
      }
      $result = $statement->fetch();
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
    if (!$result) return false;
    return true;
  }

  function addUser($db, $login, $password){
    $login = trim($login);
    if (!loginExists($db, $login) && !empty($login)) {
    try{
      error_log('going to insert into with '.$login." and ".$password);
      $statement = $db->prepare("INSERT INTO user (login, password) VALUES (:login, sha2(:password, 256))");
      if (!$statement->execute(array(':login'=>$login, ':password'=>$password))) {
        var_dump_in_error_log($db->errorInfo());
        error_log("addUser FAILED");
        return false;
      }
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
    return true;
    }
    return false;
  }
 ?>
