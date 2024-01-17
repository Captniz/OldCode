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
    echo $connectionString;

    $conn = pg_connect($connectionString);

    if (!$conn) {
        echo "Failed to connect to PostgreSQL server.";
    }else{
        echo "<br>Fatto";
        $query = "SELECT * FROM fornitori";
        $result = pg_query($conn, $query);
        $resultt = pg_fetch_assoc($result);
        echo "<br>{$resultt['nome']}<br>";
    }
    // Perform database operations here

    pg_close($conn);
?>
</body>
</html>