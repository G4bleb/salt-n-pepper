<?php
require_once 'dbconnect.php';
function generateNewGame(){
  $gameId = false;
  try{
    $statement = $dbCnx->query('INSERT INTO `game` (`id_game`) VALUES (NULL); SELECT LAST_INSERT_ID()');
    $gameId = $statement->fetchColumn();
    var_dump_in_error_log($data);
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
  return $gameId;
}
 ?>
