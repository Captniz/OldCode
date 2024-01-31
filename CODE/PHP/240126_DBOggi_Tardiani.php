<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LIBRERIA</title>
</head>
<body>
<?php
    #DATI DI LOGIN
    $host = 'localhost';
    $port = '5432';
    $dbname = 'postgres';
    $user = 'postgres';
    $password = '5130';

    #CODE
    $con=connect($host,$port,$dbname,$user,$password);    
    safequery($con,"DROP DATABASE IF EXISTS oggi");
    safequery($con,"CREATE DATABASE oggi");
    pg_close($con);
    
    $dbname = 'oggi';
    $con=connect($host,$port,$dbname,$user,$password);
    safequery($con,"CREATE TABLE studenti (nome varchar(30) PRIMARY KEY,voto int NOT NULL,reddito int NOT NULL)");
    safequery($con,"INSERT INTO studenti VALUES('Paolo',6,1500)");
    safequery($con,"INSERT INTO studenti VALUES('Marco',7,1600)");
    safequery($con,"INSERT INTO studenti VALUES('Gianni',8,1300)");
    safequery($con,"INSERT INTO studenti VALUES('Renzo',9,1200)");
    safequery($con,"INSERT INTO studenti VALUES('Toni',10,1000)");

    $res = safequery($con,"SELECT MAX(voto) FROM studenti");
    echo "Max voto: ".pg_fetch_array($res)[0]."<br>";

    $res = safequery($con,"SELECT SUM(reddito) FROM studenti WHERE voto IN (SELECT voto FROM studenti WHERE voto >= 8)");
    echo "Somma redditi alunni >= 8: ".pg_fetch_row($res)[0]."<br>";

    pg_close($conn);

    #FUNZIONI
    function safequery($con,$query){
        if(!$result=pg_query($con, $query)){
            echo pg_last_error($con);
        }
        return $result;
    }
    function connect($host,$port,$dbname,$user,$password){
        $conn = pg_connect("host={$host} port={$port} dbname={$dbname} user={$user} password={$password}");
        if (!$conn) {
           die('Connessione al database fallita.' . pg_last_error());
        }else{
            echo "<br>Connessione riuscita.<br>";
        }
        return $conn;
    }
?>
</body>
</html>