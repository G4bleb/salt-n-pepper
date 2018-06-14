<?php
/**
* @file leaderboard.php
* @brief Defines the leaderboard function
* @author Gabriel Lebis
* @date 2018-06-15
*/

require_once 'class.php';
require_once 'dbconnect.php';

/**
* Loads and displays the leaderboard table
*
* Purposefully displays blank cells for users that have no highscore
*
* @param PDO $db the PDO database
* @return HTML echo of the leaderboard
*/
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
    if (NULL != $value->getBestScore()) {//If the user has a high score
      echo '<td>'.$value->getBestScore().' pts</td>
      <td>
      <a href="mainmenu.php?gameId='.$value->getBestGameId().'">Partie n°'.$value->getBestGameId().'</a>
      </td>
      </tr>';
      // Anyone can click on the game number to challenge the user
    }
    else{
      echo '<td></td>
      <td></td>
      </tr>';
    }
  }
}

?>
