<?php
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

$secondId = array_shift($request);
if ($secondId == '')
$secondId = NULL;

if ($requestResource === 'gameList') {
  //----------------------------------------------------------------------------
  //--- request gamelist -------------------------------------------------------
  //----------------------------------------------------------------------------
  /// Sends an associative array of all games
  try{
    $statement = $dbCnx->query('SELECT * FROM game');
    $data = $statement->fetchAll(PDO::FETCH_ASSOC);
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
}elseif ($requestResource === 'loadGame') {
  //----------------------------------------------------------------------------
  //--- request loadGame -------------------------------------------------------
  //----------------------------------------------------------------------------
  /// Sends an associative array of all the questions and the themes of a game
  /// \param $id the id of the game (-1 means that a new generated game is requested)
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
    //--------------------------------------------------------------------------
    //--- request loadQuestions ------------------------------------------------
    //--------------------------------------------------------------------------
    /// Sends an associative array of all the questions of a game
    /// \param $id the id of the game (-1 means that a new generated game is requested)
    $currentGame = new Game;
    $currentGame->setId($id);
    $data = $currentGame->loadQuestions($dbCnx);

  }elseif ($requestResource === 'loadPropositions' && isset($id) && isset($secondId)) {
    //--------------------------------------------------------------------------
    //--- request loadPropositions ---------------------------------------------
    //--------------------------------------------------------------------------
    /// Sends an associative array of all the propositions of a game
    /// \param $id the id_topic of the question
    /// \param $id the num_question of the questions
    $currentQuestion = new Question;
    $currentQuestion->setId_topic($id);
    $currentQuestion->setNum_question($secondId);
    $data = $currentQuestion->loadPropositions($dbCnx);

  }elseif ($requestResource === 'addScore' && isset($id) && isset($_POST['score']) && isset($_SESSION['token'])){
    //--------------------------------------------------------------------------
    //--- request addScore -----------------------------------------------------
    //--------------------------------------------------------------------------
    /// Adds the score just done by a user to a game, only if it is the new high score. If the score is added, sends 'true'. Else, sends false.
    /// \param $id the id of the game
    /// \param $_POST['score'] the score just done
    /// \param $_SESSION['token'] the user's token (to identify him)
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
