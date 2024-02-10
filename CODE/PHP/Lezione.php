<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LEZIONE</title>
</head>
<body>
<?php
    #DATI DI LOGIN
    $host = 'localhost';
    $port = '5432';
    $dbname = 'azienda';
    $user = 'postgres';
    $password = '5130';

    $connectionString = "host={$host} port={$port} dbname={$dbname} user={$user} password={$password}";

    #CONNESSIONE
    $conn = pg_connect($connectionString);
    if (!$conn) {
        die('Connessione al database fallita.' . pg_last_error());
    }else{
        echo "<br>Connessione riuscita.<br>";
    }

    #CODE
    convertiDataEs($conn);
    getForniture($conn);
    createUser($conn, "test", "test");
    pg_close($conn);

    $user = 'test';
    $password = 'testtest';
    $connectionString = "host={$host} port={$port} dbname={$dbname} user={$user} password={$password}";

    $conn = pg_connect($connectionString);
    if (!$conn) {
        die('Connessione al database fallita.' . pg_last_error());
    }else{
        echo "<br>Connessione riuscita.<br>";
    }

    getForniture($conn);
    pg_query($conn,"INSERT INTO forniture VALUES (1,'AZX900',1200)");
    echo pg_last_error($conn);

    #FUNZIONI
    function createUser($conn, $username, $password){
        $query = "CREATE USER {$username} WITH PASSWORD '{$password}'";
        $result = pg_query($conn, $query);
        $query = "GRANT SELECT ON forniture TO {$username}";
        $result = pg_query($conn, $query);
        
        if (!$result) {
            echo "ERRORE: " . pg_last_error($conn);
        } else {
            echo "Utente creato correttamente";
        }
    }
    function convertiDataEs($conn){
        $tmp = array(
            "f_cod" => "Z0001",
            "a_cod" => "Q0001",
            "quantita" => 1012413
        );
    
        $vals=pg_convert($conn, "forniture", $tmp);
        var_dump($vals);
    }
    function getForniture($conn){
        echo "<br>Lista forniture:<br>";
        
        $query = "SELECT * FROM forniture";
        $query_r = pg_query($conn, $query);
        $result = [];
        for ($i=0; $i < pg_num_rows($query_r); $i++) { 
            //Metodo di salvataggio dati non consigliato in quanto con
            //un database molto grande potrebbe portare a problemi di memoria
            array_push($result, pg_fetch_assoc($query_r));
        }
        
        echo "<table border='1'>";
        echo "<tr><td>f_cod</td><td>a_cod</td><td>quantita</td></tr>";
        foreach ($result as $a) {
            echo "<tr>";
            foreach ($a as $key => $value) {
                echo "<td>".$value."</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }
?>
</body>
</html>