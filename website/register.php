<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Inscription</title>
  <?php require_once 'php/header.php';?>

  <h2><span class="badge badge-primary">Inscription</span></h2>
  <?php require_once 'php/sessionmanager.php'; require_once 'php/adduser.php';
  if ($sessionValid) header("Refresh:0; url=index.php");
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
  <div class="row h-75 justify-content-center align-items-center">
      <form action="register.php" method="post">
          <div class="form-group">
              <label for="username">Nom d'utilisateur</label>
              <input type="text" class="form-control" name="username" placeholder="Username">
          </div>
          <div class="form-group">
              <label for="password">Mot de passe</label>
              <input id="password" type="password" class="form-control" name="password" placeholder="Password">
          </div>
          <div class="form-group">
              <label for="confirm_password">Confirmer le mot de passe</label>
              <input id="confirm_password" type="password" class="form-control" placeholder="Confirm password"><br>
          </div>
          <span id='confirmed'></span><br>
          <input class="btn btn-primary" type="submit" name="register" value="Créer un compte" disabled="disabled">
      </form>
  </div>

  <?php require_once 'php/footer.php';?>
  <script src="js/register.js"></script>
  </html>
