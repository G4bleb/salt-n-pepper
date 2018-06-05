<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Salt'n'Pepper - Palmarès</title>

    <?php require_once 'php/header.php';?>

    <table>
      <tr>
        <th>Rang</th>
        <th>Nom</th>
        <th>Score</th>
        <th>Partie</th>
      </tr>
      <?php require_once 'php/leaderboard.php' ?>
      
    </table>

    <?php require_once 'php/footer.php';?>

</html>
