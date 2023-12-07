<?php
    $v = array();
    if(isset($_POST['col'])){
        $col = $_POST['col'];
        $ok = true;
    }
    else{
        echo 'errore: inserisci numeri';
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CicloNumeri</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <input placeholder="col" type="number" name="col" id="col" required>
        <input type="submit" value="Invia">
    </form>
    <div>
        <?php
            if($ok){
                echo '<table align="center" style="border: 2px solid black; margin-top: 100px"><tr>';
                for($i = 0 ; $i < $col ; $i++){
                    $v[$i][$j] = rand(1,25);
                    echo '<td style="border: 2px solid black; padding: 10px; color: black; background-color:white">'.$v[$i][$j].'</td>';
                }
                echo '<tr/><table/>';

                echo '<table align="center" style="border: 2px solid black; margin-top: 100px"><tr>';
                for($i = 0 ; $i < $col ; $i++){
                    if($v[$i][$j]%2 == 0){
                        echo '<td style="border: 2px solid black; padding: 10px; color: white; background-color:black">'.$v[$i][$j].'</td>';
                    }else{
                        echo '<td style="border: 2px solid black; padding: 10px; color: black; background-color:white">'.$v[$i][$j].'</td>';
                    }
           
                }
                echo '<tr/><table/>';
            }
        ?>
    </div>
</body>
</html>