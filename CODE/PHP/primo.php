<?php 
ini_set('display errors','1');
error_reporting(E_ALL | E_STRICT);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Primo</title>
</head>
<body>
    <?php 
        $user = "Jack";
        $eta = NULL;
    ?>
    <h1>
        Ciao 
        <?php
            echo $user;
        ?>
    </h1>    
</body>
</html>