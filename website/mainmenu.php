<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Menu principal</title>
  <?php require_once 'php/header.php';?>

  <h2><a href="mainmenu.php" id="mainmenu-badge"><span class="badge title-badge badge-primary">Menu principal</span></a></h2>
  <?php
  if ($sessionValid){
    if (isset($_GET['gameId'])) {
      ?>
      <ul class="list-inline justify-content-center">
        <li class="list-inline-item">
          <div id="main-div" class="menu-div"></div>
        </li>
      </ul>
      <?php
    }else{
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
    }
  }else {
    header("Refresh:0; url=login.php");
  }
  ?>

  <?php require_once 'php/footer.php';?>
  <script src="js/ajax.js"></script>
  <script src="js/default.js"></script>
  <script src="js/mainmenu.js"></script>
  </html>
