<!DOCTYPE html>
<html>
    <head>
        <title>Calcolatrice in PHP</title>
    </head>
    <body>
        <h2>Calcolatrice PHP</h2>
        <form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <input type="number" id="num1" placeholder="Inserisci il primo numero">
            <select id="operazione">
                <option value="addizione">+</option>
                <option value="sottrazione">-</option>
                <option value="moltiplicazione">*</option>
                <option value="divisione">/</option>
            </select>
            <input type="number" id="num2" placeholder="Inserisci il secondo numero">
            <button type="submit">calcola</button>
        </form>

        <?php
        if (isset($_POST['num1']) && isset($_POST['num2']) && isset($_POST['operazione'])) {
            $num1 = $_POST['num1'];
            $num2 = $_POST['num2'];
            $operazione = $_POST['operazione'];

            switch ($operazione) {
                case 'addizione':
                    $risultato = $num1 + $num2;
                    break;
                case 'sottrazione':
                    $risultato = $num1 - $num2;
                    break;
                case 'moltiplicazione':
                    $risultato = $num1 * $num2;
                    break;
                case 'divisione':
                    if ($num2 != 0) {
                        $risultato = $num1 / $num2;
                    } else {
                        echo "Impossibile dividere per zero.";
                    }
                    break;
                default:
                    echo "Operazione non valida";
                    break;
            }

            echo 'Risultato: ' . $risultato;
        }
        ?>
    </body>
</html>
