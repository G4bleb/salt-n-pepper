<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Jouer</title>
  <?php require_once 'php/header.php';?>
  <?php if ($sessionValid && isset($_GET['gameId'])): ?>
    <div id="main-div">
      <h2><span id="question" class="badge title-badge badge-primary">Connexion</span></h2>
      <h2><span id="proposition" class="badge badge-warning"></span></h2>
      <ul class="list-inline">
        <li class="list-inline-item"><h2><button id="answer1" class="bigbutton btn btn-primary"></button></h2></li>
        <li class="list-inline-item"><h2><button id="answer2" class="bigbutton btn btn-primary"></button></h2></li>
        <li class="list-inline-item"><h2><button id="answer3" class="bigbutton btn btn-primary">Les deux</button></h2></li>
      </ul>
    </div>
  <?php else: ?>
    <?php header("Refresh:0; url=login.php");?>
  <?php endif; ?>
  <?php require_once 'php/footer.php';?>
  <script src="js/ajax.js"></script>
  <script src="js/default.js"></script>
  <script src="js/play.js"></script>
  </html>
