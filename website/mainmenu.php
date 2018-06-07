<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Inscription</title>
  <link href="../css/default.css" rel="stylesheet" type="text/css">
  <?php require_once 'php/header.php';?>

  <h2><a href="mainmenu.php"><span class="badge badge-primary">Menu principal</span></a></h2>
  <?php require_once 'php/sessionmanager.php';
  if ($sessionValid){
    ?>
    <ul class="list-inline">
      <li class="list-inline-item">
        <div id="generate-game-div" class="menu-div">
          <h1><button id="generate-game" class="bigbutton btn btn-primary" >Générer une partie</button></h1>
        </div>
      </li>
      <li class="list-inline-item">
        <div id="list-games-div" class="menu-div">
          <h1><button id="list-games" class="bigbutton btn btn-primary" >Rejoindre une partie</button></h1>
        </div>
      </li>
    </ul>
    <?php
  }else {
    // error_log("NoCheckSession");
    header("Refresh:0; url=login.php");
  }

  ?>

  <?php require_once 'php/footer.php';?>
  <script src="../js/ajax.js"></script>
  <script src="../js/mainmenu.js"></script>
  </html>
