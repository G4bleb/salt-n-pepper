<?php

///Database constants.
define('DB_USER', 'etd-cir2-prj-10');
define('DB_PASSWORD', 'ewWK3oYg');
define('DB_NAME', 'etd-cir2-prj-10');
define('DB_SERVER', '127.0.0.1');

/* Connect to the db */

$mysqlServerIp = DB_SERVER;
$mysqlServerPort = "3306";
$mysqlDbName = DB_NAME;
$mysqlDbCharset = "UTF8";
$mysqlDsn = "mysql:host=".$mysqlServerIp.";port=".$mysqlServerPort.";dbname=".$mysqlDbName.";charset=".$mysqlDbCharset.";";
$myUserDb = DB_USER;
$myPwdDb = DB_PASSWORD;
$dbCnx = new PDO($mysqlDsn, $myUserDb, $myPwdDb);

if (!$dbCnx){
  header ('HTTP/1.1 503 Service Unavailable');
  exit();
}


?>
