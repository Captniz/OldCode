<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LIBRERIA</title>
</head>
<body>
<?php
    $host = 'localhost';
    $port = '5432';
    $dbname = 'azienda';
    $user = 'postgres';
    $password = '5130';

    $connectionString = "host={$host} port={$port} dbname={$dbname} user={$user} password={$password}";

    $conn = pg_connect($connectionString);

    if (!$conn) {
        die('Connessione al database fallita.' . pg_last_error());
    }else{
        echo "<br>Connessione riuscita.<br>";
    }

    echo "<br>Lista fornitori:<br>";

    $query = "SELECT * FROM fornitori";
    $query_r = pg_query($conn, $query);
    while($result = pg_fetch_assoc($query_r)){
        echo "<br>{$result['f_cod']} {$result['nome']} {$result['citta']}<br>";
    }

    pg_close($conn);
?>
</body>
</html>