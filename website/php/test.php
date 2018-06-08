<?php
require_once 'class.php';
require_once 'dbconnect.php';
$statement = $dbCnx->prepare('SELECT
	q.*
	FROM
	`question` AS q,
	`game_question` AS g
	WHERE
	g.`id_game` = :id_game AND g.`id_topic` = q.`id_topic` AND g.`num_question` = q.`num_question`
	');
	$statement->execute(array(':id_game'=>13));
	$data = $statement->fetchAll(PDO::FETCH_CLASS, 'Question');
	echo "<pre>";
	var_dump($data);
	echo "</pre>";
 ?>
