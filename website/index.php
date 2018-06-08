<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Salt'n'Pepper - Palmarès</title>
    <link href="../css/default.css" rel="stylesheet" type="text/css">

    <?php require_once 'php/header.php';?>
    <?php if ($sessionValid): ?>
      <h1><a href="mainmenu.php"><button class="bigbutton btn btn-primary" >Jouer</button></a></h1>
    <?php endif; ?>
    <table>
      <tr>
        <th>Rang</th>
        <th>Nom</th>
        <th>Score</th>
        <th>Partie</th>
      </tr>
      <?php require_once 'php/leaderboard.php';
      echoLeaderboard($dbCnx);
       ?>

    </table>

    <?php require_once 'php/footer.php';?>

</html>
