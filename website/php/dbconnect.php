<?php
/* Connexion à la BDD */

// $mysqlServerIp = "172.31.3.60";
$mysqlServerIp = "127.0.0.1";
$mysqlServerPort = "3306";
$mysqlDbName = "etd-cir2-prj-10";
$mysqlDbCharset = "UTF8";
$mysqlDsn = "mysql:host=".$mysqlServerIp.";port=".$mysqlServerPort.";dbname=".$mysqlDbName.";charset=".$mysqlDbCharset.";";
$myUserDb = 'etd-cir2-prj-10';
$myPwdDb = 'ewWK3oYg';
$dbCnx = new PDO($mysqlDsn, $myUserDb, $myPwdDb);

if (!$dbCnx){
  header ('HTTP/1.1 503 Service Unavailable');
  exit();
}


?>
