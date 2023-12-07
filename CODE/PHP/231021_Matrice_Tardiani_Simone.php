<html>
    <head>
        <title>es</title>
    </head>
    <body>
    <?php 
        $m = Array();
        carica($m, 10, 10);
        visualizza($m);
        echo "<br>";
        doppio($m);
        visualizza($m);

        function carica(&$m, $row, $col){
            for ($i = 0; $i < $row; $i++){
                $m[$i] = array();
                for ($j = 0; $j < $col; $j++){
                    $m[$i][$j]=rand(1,10);
                }
            }
        }
        function doppio(&$m){
            for ($i = 0; $i < count($m); $i++){
                for ($j = 0; $j < count($m); $j++){
                    $m[$i][$j]*=2;
                }
            }
        }
        function visualizza($m){
            foreach ($m as $i){
                foreach ($i as $j){
                    echo $j." ";
                }
                echo "<br>";
            }
        }
    ?>
    </body>
</html>