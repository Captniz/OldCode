
<?php
    // ES 1 
    echo "<br><br>";
    $constr = "host=localhost port=5432 dbname=azienda user=postgres password=5130";
    $con = pg_connect($constr);

    if(!$con){
        die ("Connessione fallita");
    }else{
        echo "Connessione riuscita al database azienda";
    }

    //ES 2
    echo "<br><br>";
    $qres = pg_query($con, "SELECT * FROM articoli");
    $res = pg_fetch_all($qres, PGSQL_ASSOC);

    echo "<table style='border: 1px solid red'>";
    foreach($res as $arr){
        echo "<tr>";
        foreach($arr as $key => $val){
            echo "<td style='border: 1px solid red'>{$val}</td>";
        }
        echo "</tr>";
    }
    echo "</table>";

    $ar = pg_affected_rows($qres);
    echo "Tuple coinvolte: {$ar}";

    //ES 3
    echo "<br><br>";
    $qres = pg_query($con, "SELECT colore,peso,citta FROM articoli");
    $res = pg_fetch_all($qres);

    foreach($res as $arr){
        foreach($arr as $key => $val){
            echo "{$val} ";
        }
        echo "<br>";
    }

    //ES 4
    echo "<br><br>";
    $qres = pg_query($con,"SELECT * FROM articoli ORDER BY a_cod DESC");
    $res = pg_fetch_all($qres);
    $ctr = 1;

    foreach($res as $arr){
        foreach($arr as $key => $val){
            echo "{$ctr}{$val} ";
            $ctr=$ctr+1;
        }
        echo "<br>";
    }

    //ES 5
    echo "<br><br>";
    $qres = pg_query($con, "SELECT DISTINCT citta,SUM(peso) AS somma FROM articoli GROUP BY citta ORDER BY SUM(peso) ASC");
    $res = pg_fetch_all($qres);
    
    foreach($res as $arr){
        foreach($arr as $key => $val){
            echo "{$key} {$val} ";
        }
        echo "<br>";
    }

    //ES 6
    echo "<br><br>";
    $qres = pg_query($con, "UPDATE articoli SET peso=peso+1 WHERE citta='Firenze'");
    $qres = pg_query($con, "SELECT * FROM articoli");
    $res = pg_fetch_all($qres);
    
    echo "<table border='1px'>";
    echo "<tr><td>";
    foreach($res as $arr){
        foreach($arr as $key => $val){
            echo "{$val} ";
        }
        echo "<br>";
    }
    echo "</td>";
    $qres = pg_query($con, "UPDATE articoli SET peso=peso-1 WHERE citta='Firenze'");
    $ar = pg_affected_rows($qres);
    $qres = pg_query($con, "SELECT * FROM articoli");
    $res = pg_fetch_all($qres);
    echo "<td>";
    foreach($res as $arr){
        foreach($arr as $key => $val){
            echo "{$val} ";
        }
        echo "<br>";
    }
    echo "</td></tr>";
    echo "Tuple coinvolte: {$ar}";
?>


<!-- 
    Errori: 
    - Generale : Mancano BR tra gli esercizi
    - Riga 6 : mancano parentesi 'die'
    - Riga 17 : $res ->> $qres
    - Riga 23 : Manca style TD
    - Riga 60 : DESC ->> ASC
    - Riga 66-80 : Manca fetch_all
    - Riga 72-85 : Query incorretta -TABLE- rimossa, peso+1 ->> peso = peso+1, ON ->> SET
    - Riga 76 : Messo border al table
    - Riga 78-90 : Correzzioni al affected_rows
-->