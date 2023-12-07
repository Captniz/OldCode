<?php
    session_start();
    if (isset($_SESSION['library'])) {
        $library=$_SESSION['library'];
    }else{
        $library=array(
            array("tit" => "Il Signore degli Anelli", "aut" => "J.R.R. Tolkien"),
            array("tit" => "Harry Potter", "aut" => "J.K. Rowling"),
            array("tit" => "1984", "aut" => "George Orwell")
        );
    }
    
    if(isset($_POST['aut']) && isset($_POST['tit']) && isset($_POST['opt'])){
        $tit = $_POST['tit'];
        $aut = $_POST['aut'];
        $opt = $_POST['opt'];
        
        if($opt == "Inserisci"){
            array_push($library, array("tit" => $tit, "aut" => $aut));
        }
        
        if($opt == "Elimina"){
            unset($library[array_search(array("tit" => $tit, "aut" => $aut), $library)]);
        }
        $_SESSION['library'] = $library;
    }
    ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LIBRERIA</title>
</head>
<body>
    <h1>Libreria</h1>
    <br>
    <?php 
        foreach($library as $lib){
            echo "<ul>".$lib['tit']." - ".$lib['aut']."</ul><br>";
        }
    ?>
    <h1>Operazioni</h1>
    <br>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <input type="text" name="tit"placeholder="Titolo">
        <input type="text" name="aut" placeholder="Autore">
        <input type="submit" name="opt" value="Inserisci">
        <input type="submit" name="opt" value="Elimina">
    </form>
</body>
</html>