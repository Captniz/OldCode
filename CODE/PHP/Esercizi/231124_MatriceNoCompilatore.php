<?php
	$dim = 8;

	if(isset($_POST['choice'])){
		$choice = $_POST['choice'];
	}


	function vis ($mat, $dim){
		echo "<table style='border: 1px solid black'>";
		for($i=0;$i<$dim;$i++){
			echo "<tr>";
			for($j=0;$j<$dim;$j++){
				echo "<td style='border: 1px solid black'>".$mat[$i][$j]."</td>";
			}
			echo "</tr>";
		}

		echo "</table>";
	}

	$mat = Array();

	for($i=0;$i<$dim;$i++){ 
		$mat[$i] = Array();
	}

	if($choice == "go"){
		$ctr=1;
		for($i=0;$i<$dim;$i++){
			for($j=0;$j<$dim;$j++){
				$mat[$i][$j] = $ctr;
				$ctr++; 
			}
		}
	}

	if($choice == "pari"){
		$ctr=1;
		for($i=0;$i<$dim;$i++){
			for($j=0;$j<$dim;$j++){
				if($ctr%2==0){
					$mat[$i][$j] = "<div style='background-color: red'>".$ctr."<div/>";
				}else{
					$mat[$i][$j] = $ctr;
				}
				$ctr++; 
			}
		}
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<title>
			MatriceSenzaCompilatore
	</title>
</head>
	<body>
		<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
			<input type="submit" name="choice" value="pari">
			<input type="submit" name="choice" value="go">
			<input type="submit" name="choice" value="delete">
		</form>

		<?php
			vis($mat, $dim);
		?>
	</body>
</html>
