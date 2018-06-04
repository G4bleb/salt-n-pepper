<!DOCTYPE html>
<html lang="fr" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Connexion</title>
  <?php require_once 'php/header.php'; ?>
  <h1><span class="label label-default">Connexion</span></h1>
  <?php if (session_status() === PHP_SESSION_NONE): ?>
    <form class="" action="login.php" method="post">
      <input type="text" name="username" value="" placeholder="Username"><br>
      <a href="#">Vous n'avez pas encore de compte ?</a><br>
      <input type="text" name="" value="" placeholder="Password"><br>
      <input type="submit" value="Connexion">
    </form>
  <?php else: ?>
    <?php require_once "php/sessionchecker.php";
    checkSession();
     ?>
  <?php endif; ?>
  <?php require_once "php/footer.php";?>
</html>
