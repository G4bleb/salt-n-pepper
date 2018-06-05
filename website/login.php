<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Connexion</title>
  <link href="../css/default.css" rel="stylesheet" type="text/css">
  <?php require_once 'php/header.php'; ?>

  <h1><span class="label label-primary">Connexion</span></h1>
  <?php require_once 'php/sessionmanager.php'; ?>
  <?php

  if (isset($_POST['connect'])) {
    error_log("connect ISSET");
    if (!startSession($dbCnx, checkLogin($dbCnx, $_POST['username'], $_POST['password']))){
      echo '<div class="alert alert-danger">Erreur de connexion : vérifiez vos identifiants</div>';
    }else{
      // error_log("SESSION STARTED");
      header("Refresh:0; url=index.php");
    }
  }
  if (isset($_GET['disconnect'])) {
    closeSession();
    header("Refresh:0; url=login.php");
  }
  ?>
<?php if (checkSession($dbCnx)): ?>
  <?php header("Refresh:0; url=index.php"); ?>
  <?php else: ?>
    <form class="" action="login.php" method="post">
    <input type="text" name="username" value="" placeholder="Username"><br>
    <a href="register.php">Vous n'avez pas encore de compte ?</a><br>
    <input type="password" name="password" value="" placeholder="Password"><br>
    <input class="btn btn-default" type="submit" value="Connexion" name="connect">
    </form>
<?php endif; ?>
  <?php require_once "php/footer.php";?>
  </html>
