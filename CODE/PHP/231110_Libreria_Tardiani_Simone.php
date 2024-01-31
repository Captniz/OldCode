<?php
    $ask="";
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
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CicloNumeri</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <input placeholder="Titolo" type="text" name="tit" id="tit" required>
        <input placeholder="Autore | Nome e Cognome |" type="text" name="aut" id="aut" required>
        <input type="submit" value="Invia" name="ask">
        <input type="submit" value="Elimina" name="ask">
    </form>
    <div>
        <?php
                $libri = array(
                    array("tit" => "Il Signore degli Anelli", "aut" => "J.R.R. Tolkien"),
                    array("tit" => "Harry Potter", "aut" => "J.K. Rowling"),
                    array("tit" => "1984", "aut" => "George Orwell")
                );

                if($ask=="Invia"){
                    array_push($libri,$tmplib);
                }elseif($ask=="Elimina"){
                    for($i=0;$i<count($libri);$i++){
                        if($libri[$i]["tit"]== $tit && $libri[$i]["aut"]== $aut){
                            $libri[$i]=null;
                        }
                    }
                }

                foreach($libri as $lib){
                    if($lib!=null){
                        echo '<h3>'.$lib['tit'].' - '.$lib['aut'].'<h3>';
                    }
                }
        ?>
    </div>
</body>
</html>