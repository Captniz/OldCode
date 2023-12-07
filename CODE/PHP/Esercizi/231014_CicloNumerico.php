<?php
    if(isset($_POST['numero'])){
        $numero = $_POST['numero'];
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
        <input type="number" name="numero" id="numero" required>
        <input type="submit" value="Invia">
    </form>
    <div>
        <?php
            $ctr = 0;
            for ($i=1; $i <= $numero; $i++) { 
                echo $i . " ";
                $ctr++;
                if ($ctr == 10) {
                    echo "<br>";
                    $ctr = 0;
                }
            }
        ?>
    </div>
</body>
</html>