<!DOCTYPE html>
<html>
	<head>
		<title>es1 - Tardiani Simone</title>
	</head>
	<body>
		<h1>ES 1 - Tardiani Simone</h1>
		<?php
			$alunni = Array(
				"Zibordi" => 95,
				"Veneri" => 90,
				"Rodella" => 96,
				"Anton" => 93,
				"Bini" => 98
			);
			$cognomi = array();
			
			$ctr=0;
			foreach($alunni as $n => $v){
				echo "Studente: ".$n." - Voto: ".$v."<br/>";
				
				array_push($cognomi,$n);
				
				$ctr += $v; 
			}
			echo "<br>Somma voti: ".$ctr;
			
			for($i=0;$i<count($cognomi)-1;$i++){
				for($j=($i+1);$j<count($cognomi);$j++){
					if($cognomi[$i]>$cognomi[$j]){
						$tmp = $cognomi[$i];
						$cognomi[$i] = $cognomi[$j];
						$cognomi[$j] = $tmp;
					}
				}
			}
			
			echo "<br><br>Alunni ordinati:<br>";
			foreach($cognomi as $n){
				echo $n."<br/>";
			}
		?>
	</body>
</html>