<?php
    if(isset($_POST['pos'])){
        $pos=$_POST['pos'];
        $tmp=explode(",",$pos);
        $ti=$tmp[0];
        $tj=$tmp[1];
    }else{
        $ti=-1;
        $tj=-1;
    }
?>

<!DOCTYPE html>
<html>
    <head>
        <title>
            Croce
        </title>
    </head>
    <body>
        <form action="<?php echo $_SERVER['PHP_SELF'];?>" method="POST">
            <?php 
                echo "<table>";
                for($i=0; $i<10;$i++){
                    echo "<tr>";
                    for($j=0; $j<10;$j++){
                        echo "<td><input type='submit' name='pos' value='".$i.",".$j."' ";
                        if($i==$ti || $j==$tj){
                            echo "style='background-color:red'";
                        }
                        echo "></td>";
                    }
                    echo "</tr>";
                }
                echo "</table>";
                ?>  
        </form> 
    </body>
</html>