<?php
require_once 'dbconnect.php';
session_start();
function checkSession($db){
  error_log("checkSession : ");
  if (!isset($_SESSION['token'])) return false;
  $statement = $db->prepare('SELECT * FROM user WHERE token=:token');
  $statement->execute(array(':token'=>$_SESSION['token']));
  $result = $statement->fetch();
  error_log($result['login']);
  if (!$result){
    closeSession();
    return false;
  }
  return true;
}

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

function closeSession(){
  error_log("closeSession");
  // session_unset();
  // session_destroy();
  $_SESSION = array();
}

function checkLogin($db, $login, $password){
  try{
    error_log("checkingLogin : ".$login.", ".$password);
    $statement = $db->prepare("SELECT id_user FROM user WHERE login=:login AND password=sha2(:password, 256)");
    if (!$statement->execute(array(':login'=>$login, ':password'=>$password))) {
      error_log("checkLogin FAILED");
    }
    $result = $statement->fetch();
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
  error_log("returning ".$result['id_user']);
  if (!$result) return false;
  return $result['id_user'];

}
?>
