<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Salt'n'Pepper - Inscription</title>

  <?php include 'php/header.php';?>
  <div id="content">
    <?php require_once 'php/sessionmanager.php';
    if (checkSession($dbCnx)) header("Refresh:0; url=index.php");
    if (isset($_POST['register'])) {
      
    }
?>
  </div>
  <?php include 'php/footer.php';?>
</html>
