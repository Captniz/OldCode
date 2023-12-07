<?php
	if(isset($_POST['col']) && isset($_POST['row'])){
		$col = $_POST['col']-1;
		$row = $_POST['row']-1;
		$diff=($col+$row)-($row*2);
		$ok=1;
	}else{
		$ok=0;
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<title>es2 - Tardiani Simone</title>
	</head>
	<body>
		<h1>ES 2 - Tardiani Simone</h1>
		<form method="POST" action="Verifica_02.php">
			<input type="number" placeholder="row" name="row">
			<input type="number" placeholder="col" name="col"> 
			<input type="submit" name="ok" value="ok">
		</form>
		<?php
			if($ok==1){
				echo "<br><br><table style='border: solid 2px black'>";
				for($i=0;$i<8;$i++){
					echo "<tr>";
					for($j=0;$j<8;$j++){
						if($i+$j >= $diff+($i*2)){
							echo "<td style='font-weight:bold;text-align:center;height: 15px; width:15px; background-color: #ffdddd'>1</td>";
						}else{
							echo "<td style='text-align:center;height: 15px; width:15px; background-color: #a7deee'>0</td>";
						}
					}	
					echo "</tr>";
				}
				echo "</table>";
			}
		?>
	</body>
</html>