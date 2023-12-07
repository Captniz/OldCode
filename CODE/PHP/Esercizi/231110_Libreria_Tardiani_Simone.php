<?php
/*09> 231110_libreria.php
Esercizio PHP sugli Array Associativi con Interfaccia Web: Libreria Online

Creare una pagina web in PHP che gestisca una libreria online. La pagina deve visualizzare una lista iniziale di libri con titolo e autore. Inoltre, deve fornire un modulo per consentire agli utenti di aggiungere nuovi libri alla libreria.
Inizializzare un array associativo di libri con almeno tre libri predefiniti (titolo e autore).
<?php
// Inizializzazione dell'array associativo dei libri
$libri = array(
    array("titolo" => "Il Signore degli Anelli", "autore" => "J.R.R. Tolkien"),
    array("titolo" => "Harry Potter", "autore" => "J.K. Rowling"),
    array("titolo" => "1984", "autore" => "George Orwell")
);

Visualizzazione della Lista dei Libri:
Mostrare la lista dei libri sulla pagina utilizzando HTML e PHP.

Modulo di Aggiunta Libro:
Creare un modulo HTML con campi per il titolo e l'autore di un nuovo libro.
Utilizzare il metodo POST per inviare i dati del modulo a PHP.
Gestione Aggiunta Libro:

Nel file PHP, ricevere i dati inviati dal modulo.
Validare i dati [data entry](assumendo che entrambi i campi siano obbligatori).
Aggiungere il nuovo libro all'array associativo dei libri.

Aggiornamento della Lista:
Dopo l'aggiunta di un nuovo libro, aggiornare la visualizzazione della lista dei libri sulla pagina.

Ulteriori Miglioramenti (Opzionale):
Aggiungere ulteriori controlli di validazione dei dati (lunghezza massima, caratteri consentiti, ecc.).

Implementare la possibilità di rimuovere libri dalla lista.
Mantenere la pagina web ben formattata e fornire feedback agli utenti dopo l'aggiunta di un nuovo libro. Puoi utilizzare stili CSS per migliorare l'aspetto della pagina.
 */
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