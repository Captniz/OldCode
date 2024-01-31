<?php
    if(isset($_POST['tit']) && isset($_POST['aut'])){
        $ask = $_POST['ask'];
        $tit = $_POST['tit'];
        $aut = $_POST['aut'];
        $tmplib = array('tit'=>$_POST['tit'], 'aut' => $_POST['aut']);    
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LIBRERIA</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <select name="Database" >
            <option value="err">
                DATABASE
            </option>
            <option value="alfa">
                Alfa
            </option>
            <option value="beta">
                Beta
            </option>
        </select>
        <select name="Table">
            <option value="err">
                TABLE
            </option>
            <option value="alunni">
                Alunni
            </option>
            <option value="prof">
                Prof
            </option>
            <option value="materie">
                Materie
            </option>
        </select>
        <input type="submit" value="Cerca">
    </form>
            



<?php
    #DATI DI LOGIN
    $host = 'localhost';
    $port = '5432';
    $dbname = 'alfa';
    $user = 'postgres';
    $password = '5130';

    #CODE
    $con = s_connect($host,$port,$dbname,$user,$password);
    $qres = s_query($con, "SELECT * FROM alunni");
    $res = pg_fetch_all($qres,PGSQL_ASSOC);
    write_table($res,$qres);
    pg_close($con);


    pg_close($con);


    #FUNZIONI
    function s_connect($host,$port,$dbname,$user,$password){
        $connectionString = "host={$host} port={$port} dbname={$dbname} user={$user} password={$password}";
        $conn = pg_connect($connectionString);
        if (!$conn) {
            die('Connessione al database fallita.' . pg_last_error());
        }else{
            echo "<br>Connessione riuscita.<br>";
        }
        return $conn;
    }
    function s_query($con,$query){
        if(!$result=pg_query($con, $query)){
            echo pg_last_error($con);
        }
        return $result;
    }
    function write_table($res,$qres){
        echo "<table border='1'>";
        echo "<tr>";
        for ($i=0; $i < pg_num_fields($qres); $i++) { 
            echo "<td>";
            echo pg_field_name($qres,$i);
            echo "</td>";
        }
        echo "</tr>";
        foreach ($res as $arr) {
            echo "<tr>";
            foreach ($arr as $key => $value) {
                echo "<td>";
                echo $value;
                echo "</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }
?>
</body>
</html>