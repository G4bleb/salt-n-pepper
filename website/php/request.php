<?php
/**
* @file request.php
* @brief ajaxRequests handler
* @author Gabriel Lebis
* @date 2018-06-15
*
* Splits the request to extract potential data, executes php functions in consequence, sends the data
*
*/

///request.php : file used for ajax requests
require_once 'class.php';
require_once 'dbconnect.php';
require_once 'sessionmanager.php';
require_once 'newgame.php';
header('Content-Type: text/plain; charset=utf-8');
header('Cache-control: no-store, no-cache, must-revalidate');
header('Pragma: no-cache');

/// Check the request
$requestType = $_SERVER['REQUEST_METHOD'];


if (isset($_SERVER['PATH_INFO'])) {// If there's something to extract from the path
  $request = substr($_SERVER['PATH_INFO'], 1);
}else{
  $request = '';
}

/// Cut the url into an array using the '/' as separators
$request = explode('/', $request);
/// The first value is the request resource
$requestResource = array_shift($request);
/// Default value of $data
$data = $requestType.':'.$requestResource;

/// Load the id(s) sent with the request.
$id = array_shift($request);
if ($id == '')
$id = NULL;
/// Load the id(s) sent with the request.
$secondId = array_shift($request);
if ($secondId == '')
$secondId = NULL;



if ($requestResource === 'gameList') {
  /**
  * - gamelist
  * @brief Sends an associative array of all games
  */
  try{
    $statement = $dbCnx->query('SELECT * FROM game');
    $data = $statement->fetchAll(PDO::FETCH_ASSOC);
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }

}elseif ($requestResource === 'loadGame' && isset($id)) {
  /**
  * - loadGame
  * @brief Sends an associative array of all the questions and the themes of a game
  * @param int $id the id of the game (-1 means that a new generated game is requested)
  */
  if ($id == -1) {
    $id = generateNewGame($dbCnx);
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
    }
    catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
  }elseif ($requestResource === 'loadQuestions' && isset($id)) {
    /**
    * - loadQuestions
    * @brief Sends an associative array of all the questions and labels of a game
    * @param int $id the id of the game
    */
    $currentGame = new Game;
    $currentGame->setId($id);
    $data = $currentGame->loadQuestions($dbCnx);

  }elseif ($requestResource === 'loadPropositions' && isset($id) && isset($secondId)) {
    /**
    * - loadPropositions
    * @brief Sends an associative array of all the propositions of a game
    * @param int $id the id_topic of the question
    * @param $id the num_question of the questions
    */
    $currentQuestion = new Question;
    $currentQuestion->setId_topic($id);
    $currentQuestion->setNum_question($secondId);
    $data = $currentQuestion->loadPropositions($dbCnx);

  }elseif ($requestResource === 'addScore' && isset($id) && isset($_POST['score']) && isset($_SESSION['token'])){
    /**
    * - addScore
    * @brief Sends the score just done by a user to a game, only if it is the new high score
    * Sends true if the score is a high score, else sends false
    * @param int $id the id of the game
    * @param int $_POST['score'] the score just done
    * @param string $_SESSION['token'] the user's token (to identify him)
    */
    try {
      $statement = $dbCnx->prepare('SELECT id_user, best_score FROM user WHERE token=:token');
      $statement->execute(array(':token'=>$_SESSION['token']));
      $result = $statement->fetchAll(PDO::FETCH_ASSOC);;
      $data = false;
      if ($_POST['score']>$result[0]['best_score']) {
        $statement = $dbCnx->prepare("UPDATE user SET best_score=:best_score, id_game=:id_game WHERE id_user=:id_user");
        $statement->execute(array(':best_score'=>$_POST['score'], ':id_game'=>$id,':id_user'=>$result[0]['id_user']));
        $data = true;
      }
    } catch (PDOException $exception){
      error_log('Request error: '.$exception->getMessage());
      return false;
    }
  }
  // Send data to the client
  header('HTTP/1.1 200 OK');
  echo json_encode($data);
  exit();
  ?>
