<?php
require_once 'dbconnect.php';

//------------------------------------------------------------------------------
//--- generateNewGame ----------------------------------------------------------
//------------------------------------------------------------------------------
/// Generates a new game from the database with 3 random questions
/// \param $db the PDO database
/// \return the id of the game just generated, or false if the function failed
function generateNewGame($db){
  $gameId = false;
  try{
    $statement = $db->exec('INSERT INTO `game` (`id_game`) VALUES (NULL)');
    $gameId = $db->lastInsertId();
  }
  catch (PDOException $exception){
    error_log('Request error on game insertion: '.$exception->getMessage());
    return false;
  }
  try{
    $statement = $db->query('SELECT `id_topic`,`num_question` FROM `question` WHERE `enabled` = 1 ORDER BY RAND() LIMIT 3');
    // Three questions, chosen randomly
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
