<?php

require_once 'dbconnect.php';

//------------------------------------------------------------------------------
//--- loginExists --------------------------------------------------------------
//------------------------------------------------------------------------------
/// Checks if the login given in parameter already exists (so there is no duplicate user)
/// \param $db the PDO database
/// \param $login the login to check
/// \return true or false
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

//------------------------------------------------------------------------------
//--- addUser ------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Adds the given user to the database
/// \param $db the PDO database
/// \param $login the login to add
/// \param $password the password to add
/// \return true or false depending on the success of the insertion
function addUser($db, $login, $password){
  $login = trim($login);//We remove spaces that could have been mistakenly entered
  if (!loginExists($db, $login) && !empty($login) && preg_match('/^[0-9A-Za-zÀ-ÖØ-öø-ÿ-]+$/', $login)) {
      //The regular expression checks for letters, numbers, and most of the special European characters
    try{
      $statement = $db->prepare("INSERT INTO user (login, password) VALUES (:login, sha2(:password, 256))");
          //The password is hashed by the database
      if (!$statement->execute(array(':login'=>$login, ':password'=>$password))) {
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
