<?php
/**
* @file dbconnect.php
* @brief connects to the database, to use the PDO $dbCnx later
* @author Gabriel Lebis
* @date 2018-06-15
*/

///Database constants.
define('DB_USER', 'etd-cir2-prj-10');
define('DB_PASSWORD', 'ewWK3oYg');
define('DB_NAME', 'etd-cir2-prj-10');
define('DB_SERVER', '127.0.0.1');
define('DB_CHARSET', 'UTF8');
define('DB_PORT', '3306');
/* Connect to the db */

$mysqlDsn = "mysql:host=".DB_SERVER.";port=".DB_PORT.";dbname=".DB_NAME.";charset=".DB_CHARSET.";";
$dbCnx = new PDO($mysqlDsn, DB_USER, DB_PASSWORD);

if (!$dbCnx){
  header ('HTTP/1.1 503 Service Unavailable');
  exit();
}


?>
