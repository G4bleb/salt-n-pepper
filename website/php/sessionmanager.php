<?php
require_once 'dbconnect.php';
session_start();
function checkSession($db){
  if (!isset($_SESSION['token'])) return false;
  $statement = $db->prepare('SELECT * FROM user WHERE token=:token');
  $statement->execute(array(':token'=>$_SESSION['token']));
  $result = $statement->fetch();
  if (!$result) return false;
  return $result['login'];
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
  // session_unset();
  session_destroy();
}

function checkLogin($db, $login, $password){
  try{
    $statement = $db->prepare('SELECT id_user FROM user WHERE login=:login AND password=sha2(:password, 256)');
    $statement->execute(array(':login'=>$login, ':password'=>$password));
    $result = $statement->fetch();
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }

  if (!$result) return false;
  return $result['id_user'];
  var_dump($result['id_user']);
}
?>
