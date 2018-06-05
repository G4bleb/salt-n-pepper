<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Inscription</title>
  <link href="../css/default.css" rel="stylesheet" type="text/css">
  <?php require_once 'php/header.php';?>

  <h1><span class="label label-primary">Inscription</span></h1>
  <?php require_once 'php/sessionmanager.php'; require_once 'php/adduser.php';
  if (checkSession($dbCnx)) header("Refresh:0; url=index.php");
  if (isset($_POST['register'])) {
    if (addUser($dbCnx, $_POST['username'], $_POST['password'])) {
      error_log("addedUser : ".$_POST['username'].", ".$_POST['password']);
      if (startSession($dbCnx, checkLogin($dbCnx, $_POST['username'], $_POST['password']))) {
        header("Refresh:0; url=index.php");
      }
    }else {
      echo '<div class="alert alert-danger">Erreur d\'inscription : choisissez un autre pseudo</div>';
    }
  }
  ?>
  <form action="register.php" method="post">
    <label for="username">Nom d'utilisateur</label>
    <input type="text" name="username" value="" placeholder="Username"><br>
    <label for="password">Mot de passe</label>
    <input id="password" type="password" name="password" value="" placeholder="Password"><br>
    <label for="confirm_password">Confirmer le mot de passe</label>
    <input id="confirm_password" type="password" name="" value="" placeholder="Confirmer password"><br>
    <span id='confirmed'></span><br>
    <input class="btn btn-default" type="submit" name="register" value="Créer un compte">
  </form>

  <?php require_once 'php/footer.php';?>
  <script src="../js/register.js"></script>
  </html>
