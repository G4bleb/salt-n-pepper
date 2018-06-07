<?php
require_once 'dbconnect.php';
require_once 'game.php';
header('Content-Type: text/plain; charset=utf-8');
header('Cache-control: no-store, no-cache, must-revalidate');
header('Pragma: no-cache');
// Database connection.
if (!$dbCnx){
  header ('HTTP/1.1 503 Service Unavailable');
  exit();
}

// Check the request.
$requestType = $_SERVER['REQUEST_METHOD'];

if (isset($_SERVER['PATH_INFO'])) { //If there's something to extract from the path
  $request = substr($_SERVER['PATH_INFO'], 1);
}else{
  $request = '';
}

$request = explode('/', $request);
$requestRessource = array_shift($request);
$data = $requestType.':'.$requestRessource;

// Check the id associated to the request.
$id = array_shift($request);
if ($id == '')
$id = NULL;

if ($requestRessource === 'gamelist') {
  try{
    $statement = $dbCnx->query('SELECT * FROM game');
    $data = $statement->fetchAll(PDO::FETCH_ASSOC);
    var_dump_in_error_log($data);
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
}elseif ($requestRessource === 'loadGame') {
  if ($id == -1) {
    $id = generateNewGame();
  }
  try{
    $statement = $dbCnx->prepare('SELECT
      `id_game`,
      `main_question`,
      `topic_name`
      FROM
      `question` AS q,
      `game_question` AS g,
      `topic` AS t
      WHERE
      g.`id_game` = :id_game AND g.`id_topic` = q.`id_topic` AND g.`num_question` = q.`num_question` AND q.`id_topic` = t.`id_topic`
      ');
      $statement->execute(array(':id_game'=>$id));
      $data = $statement->fetchAll(PDO::FETCH_ASSOC);
      var_dump_in_error_log($data);
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
  }

  // Send data to the client.

  header('HTTP/1.1 200 OK');
  echo json_encode($data);
  exit;
  ?>
