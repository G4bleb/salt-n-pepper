<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Inscription</title>
  <link href="../css/default.css" rel="stylesheet" type="text/css">
  <script src="../js/jquery-3.3.1.min.js"></script>
  <?php include 'php/header.php';?>
  <div id="content">
    <h1><span class="label label-primary">Inscription</span></h1>
    <?php require_once 'php/sessionmanager.php'; require_once 'php/adduser.php';
    if (checkSession($dbCnx)) header("Refresh:0; url=index.php");
    if (isset($_POST['register'])) {
      if (addUser($dbCnx, $_POST['username'], $_POST['password'])) {
        startSession($dbCnx, checkLogin($dbCnx, $_POST['username'], $_POST['password']));
        header("Refresh:0; url=index.php");
      }
      else {
        echo "ERREUR D'INSCRIPTION";
      }
    }
    ?>
    <form class="" action="register.php" method="post">
      <label for="username">Nom d'utilisateur</label>
      <input type="text" name="username" value="" placeholder="Username"><br>
      <label for="password">Mot de passe</label>
      <input id="password" type="password" name="password" value="" placeholder="Password"><br>
      <label for="confirm_password">Confirmer le mot de passe</label>
      <input id="confirm_password" type="password" name="" value="" placeholder="Confirmer password"><br>
      <span id='confirmed'></span><br>
      <input class="btn btn-default" type="submit" name="register" value="Créer un compte">
    </form>
  </div>
  <?php include 'php/footer.php';?>
  <script src="../js/register.js"></script>
  </html>
