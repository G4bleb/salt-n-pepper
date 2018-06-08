<?php
require_once 'class.php';
require_once 'dbconnect.php';

function echoLeaderboard($db){
  try{
    $statement = $db->query('SELECT * FROM user ORDER BY best_score DESC');
    $users = $statement->fetchAll(PDO::FETCH_CLASS, 'User');
  }
  catch (PDOException $exception){
    error_log('Request error: '.$exception->getMessage());
    return false;
  }
  foreach ($users as $key => $value) {
    if ($key>24) {//A maximum of 25 users are shown
      break;
    }
    echo '<tr>
    <td>Numéro '.($key+1).'</td>
    <td>'.$value->getLogin().'</td>';
    if (NULL != $value->getBestScore()) {
      echo '<td>'.$value->getBestScore().' pts</td>
      <td><a href="play.php?gameId='.$value->getBestGameId().'">Partie n°'.$value->getBestGameId().'</a></td>
      </tr>';
    }
    else{
      echo '<td></td>
      <td></td>
      </tr>';
    }
  }
}

?>
