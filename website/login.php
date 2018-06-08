<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Connexion</title>
  <link href="../css/default.css" rel="stylesheet" type="text/css">
  <?php require_once 'php/header.php'; ?>

  <h2><span class="badge badge-primary">Connexion</span></h2>
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
    <!-- <div class="row h-75 justify-content-center align-items-center">
    <form action="login.php" method="post">
    <input class="col-2 form-control" type="text" name="username" value="" placeholder="Username"><br>
    <a href="register.php">Vous n'avez pas encore de compte ?</a><br>
    <input class="col-2 form-control" type="password" name="password" value="" placeholder="Password"><br>
    <input class="btn btn-primary" type="submit" value="Connexion" name="connect">
  </form>
</div> -->
<div class="row h-75 justify-content-center align-items-center">
  <form action="login.php" method="post">
    <div class="form-group">
      <label for="username">Nom d'utilisateur</label>
      <input type="text" class="form-control" name="username" placeholder="Username">
    </div>
    <div class="form-group">
      <label for="password">Mot de passe</label>
      <input type="password" class="form-control" name="password" placeholder="Password">
    </div>
    <input class="btn btn-primary" type="submit" value="Connexion" name="connect">
  </form>
</div>
<?php endif; ?>
<?php require_once "php/footer.php";?>
</html>
