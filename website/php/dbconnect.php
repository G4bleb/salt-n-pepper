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
$dbCnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$dbCnx->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);

function var_dump_in_error_log( $object=null ){
    ob_start();                    // start buffer capture
    var_dump( $object );           // dump the values
    $contents = ob_get_contents(); // put the buffer into a variable
    ob_end_clean();                // end capture
    error_log( $contents );        // log contents of the result of var_dump( $object )
}


?>
