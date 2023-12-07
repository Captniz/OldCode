<!-- make a page that takes base and height of a rectangle and draws it to the screen using php-->
<!DOCTYPE html>
<html>
<head>
    <title>Rectangle</title>
</head>
<body>
    <form action="rectangle.php" method="post">
        <input type="text" name="base" placeholder="Base">
        <input type="text" name="height" placeholder="Height">
        <input type="submit" name="submit" value="Submit">
    </form>

    <?php
        if(isset($_POST['submit'])){
            $base = $_POST['base'];
            $height = $_POST['height'];
            echo "<svg width='400' height='110'>
                    <rect width='$base' height='$height' style='fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)' />
                </svg>";
        }
    ?>
</body>
</html>