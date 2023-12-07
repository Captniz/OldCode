<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CicloNumeri</title>
</head>
<body>
    <div>
        <?php
            /*
            - Manca $ negli indici degli array
            - Manca nome funzione
            - Ho confuso una parentesi: serve una parentesi graffa chiusa subito dopo la chiusura dell'else
            */
            $vet=array(3,4,5,6,7);
            $mat;
            $DIM=5;

            $mat= carica($vet,$mat,$DIM);

            for ($i= 0; $i< $DIM; $i++) {
                for ($j= 0; $j< $DIM; $j++){
                    echo ''.$mat[$i][$j];
                }
                echo '<br>';
            }


            function carica($vet,$mat,$DIM){
                $mat=array();
                for ($i= 0; $i<$DIM; $i++){
                    $tmp=array();
                    for ($j= 0; $j<$DIM; $j++){
                        if ($j%2== 0){
                            $tmp[$j]=$vet[$i];
                        }else{
                            $tmp[$j]=$vet[count($vet)-$i-1];
                        }
                    }
                    $mat[$i]=$tmp;
                }
                return $mat;
            }
            
        ?>
    </div>
</body>
</html>