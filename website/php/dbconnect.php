<?php
require_once 'class.php';

/* Connexion à la BDD */

// $mysqlServerIp = "172.31.3.60";
$mysqlServerIp = "localhost";
$mysqlServerPort = "3306";
$mysqlDbName = "etd-cir2-prj-10";
$mysqlDbCharset = "UTF8";
$mysqlDsn = "mysql:host=".$mysqlServerIp.";port=".$mysqlServerPort.";dbname=".$mysqlDbName.";charset=".$mysqlDbCharset.";";
$myUserDb = 'etd-cir2-prj-10';
$myPwdDb = 'ewWK3oYg';
$dbCnx = new PDO($mysqlDsn, $myUserDb, $myPwdDb);
?>
