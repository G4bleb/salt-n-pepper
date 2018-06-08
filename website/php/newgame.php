<?php
require_once 'dbconnect.php';
function generateNewGame($db){
  $gameId = false;
  try{
    $statement = $db->exec('INSERT INTO `game` (`id_game`) VALUES (NULL)');
    $gameId = $db->lastInsertId();
    var_dump_in_error_log($gameId);
  }
  catch (PDOException $exception){
    error_log('Request error on game insertion: '.$exception->getMessage());
    return false;
  }
  try{
    $statement = $db->query('SELECT `id_topic`,`num_question` FROM `question` ORDER BY RAND() LIMIT 3');
    $questions = $statement->fetchAll(PDO::FETCH_ASSOC);
    foreach ($questions as $key => $question) {
      try {
        $statement = $db->prepare("INSERT INTO `game_question` (`id_game`, `id_topic`, `num_question`) VALUES (:id_game, :id_topic, :num_question)");
        if (!$statement->execute(array(':id_game'=>$gameId, ':id_topic'=>$question['id_topic'], ':num_question'=>$question['num_question']))) {
          error_log("Linking between game and questions failed");
          return false;
        }
      } catch (PDOException $exception){
        error_log('Request error on game_question insertion: '.$exception->getMessage());
        return false;
      }
    }
  }
  catch (PDOException $exception){
    error_log('Request error on question query: '.$exception->getMessage());
    return false;
  }
  return $gameId;
}
?>
