<?php
/**
* @file sessionmanager.php
* @brief Defines session-managing functions
* @author Gabriel Lebis
* @date 2018-06-15
*/

require_once 'dbconnect.php';
session_start();

/**
* Checks if the user's session is valid
*
* @param PDO $db the PDO database
* @return bool true or false, whether the session is valid
*/
function checkSession($db){
  error_log("Checking session");
  if (!isset($_SESSION['token'])) return false;
  $statement = $db->prepare('SELECT * FROM user WHERE token=:token');
  $statement->execute(array(':token'=>$_SESSION['token']));
  $result = $statement->fetch();
  if (!$result){
    closeSession();
    return false;
  }
  return true;
}

/**
* Setups a user's session
*
* @param PDO $db the PDO database
* @param int $userId the user's id
* @return bool true if the function succeeded, false if it failed
*/
function startSession($db, $userId){
  if ($userId) {
    $_SESSION['token']=base64_encode(openssl_random_pseudo_bytes(12));
    $statement = $db->prepare("UPDATE user SET token=:token WHERE id_user=:id_user");
    $statement->execute(array(':token'=>$_SESSION['token'],':id_user'=>$userId));
    return true;
  }else{
    error_log("startSession error : userId : $userId");
    return false;
  }
}

/**
* Closes a user's session (empties it)
*/
function closeSession(){
  error_log("closeSession");
  $_SESSION = array();
}

/**
* Checks a user's credentials to connect
*
* @param PDO $db the PDO database
* @param string $login the form-sent login
* @param string $password the form-sent password
* @return int the user's id
* @return bool false if the function failed
*/
function checkLogin($db, $login, $password){
  try{
    error_log("checkingLogin : ".$login.", ".$password);
    $statement = $db->prepare("SELECT id_user FROM user WHERE login=:login AND password=sha2(:password, 256)");
    if (!$statement->execute(array(':login'=>$login, ':password'=>$password))) {
      error_log("checkLogin FAILED");
    }
    $result = $statement->fetchColumn();
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
  error_log("returning ".$result);
  if (!$result) return false;
  return $result;
}
?>
