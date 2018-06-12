<?php
require_once 'dbconnect.php';
session_start();

//------------------------------------------------------------------------------
//--- checkSession -------------------------------------------------------------
//------------------------------------------------------------------------------
// Checks if the user's session is valid
// \param db the PDO database
// \return true or false, whether the session is valid
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

//------------------------------------------------------------------------------
//--- startSession -------------------------------------------------------------
//------------------------------------------------------------------------------
// Setups a user's session
// \param db the PDO database
// \param userId the user's id
// \return true if the function succeeded, false if it failed
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

//------------------------------------------------------------------------------
//--- closeSession -------------------------------------------------------------
//------------------------------------------------------------------------------
// Closes a user's session (empties it)
function closeSession(){
  error_log("closeSession");
  $_SESSION = array();
}
//------------------------------------------------------------------------------
//--- checkLogin ---------------------------------------------------------------
//------------------------------------------------------------------------------
// Checks a user's credentials to connect
// \param db the PDO database
// \param login the form-sent login
// \param password the form-sent password
// \return the user's id, or false is the function failed
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
