<?php
    session_start();
    if(isset($_POST['dbb'])){
        $_SESSION = $_POST;
    }else{
        $_SESSION=[
            "srv" => "",
            "prt" => "",
            "usr" => "",
            "psw" => "",
            "dbb" => "",
            "tbb" => ""
        ];
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Preverifica</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <input type="text" placeholder="Server" name="srv" value="<?php echo $_SESSION['srv'] ?>"/>
        <input type="text" placeholder="Port" name="prt" value="<?php echo $_SESSION['prt'] ?>"/>
        <input type="text" placeholder="Username" name="usr" value="<?php echo $_SESSION['usr'] ?>"/>
        <input type="text" placeholder="Password" name="psw" value="<?php echo $_SESSION['psw'] ?>"/>
        <br>
        <br>
        <input type="text" placeholder="Database" name="dbb" value="<?php echo $_SESSION['dbb'] ?>"/>
        <input type="text" placeholder="Table" name="tbb" value="<?php echo $_SESSION['tbb'] ?>"/>
        <input type="submit" name="cnn" value="CONNECT"/>
        <br>
        <br>
    </form>

    <?php
        #CODE
        try{  
            if(!($_SESSION['dbb'] == "")){
                $con=connect($_SESSION["srv"],$_SESSION["prt"],$_SESSION["dbb"],$_SESSION["usr"],$_SESSION["psw"]);

                //QUERIES
                $res=safequery($con,"SELECT * FROM {$_SESSION['tbb']}");
                #$res=safequery($con,"SELECT SUM(quantita) FROM {$_SESSION['tbb']}");
                write_table($res);
            }
        }catch(Exception $e){
            echo "Errore :: ".$e->getMessage();
        }
        pg_close($con);

        #FUNZIONI
        function safequery($con,$query){
            if(!$result=pg_query($con, $query)){
                throw new Exception('Errore nella query: '.pg_last_error($con));
            }
            return $result;
        }
        function connect($host,$port,$dbname,$user,$password){
            $conn = pg_connect("host={$host} port={$port} dbname={$dbname} user={$user} password={$password}");
            if (!$conn) {
                throw new Exception('Connessione al database fallita');
            }
            return $conn;
        }
        function write_table($qres){
            $res=pg_fetch_all($qres,PGSQL_ASSOC);
            echo "<table border='1' style='text-align: center'>";
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