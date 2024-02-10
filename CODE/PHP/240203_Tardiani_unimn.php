<?php
	$sub = "boh";
	if(isset($_POST['sub'])){
		$sub = $_POST['sub'];
	}
?>

<!DOCTYPE html>
<html>
<head>
	<title>Verifica</title>
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']?>" method="POST">
		<p>SELECT * FROM studenti;</p><input type=submit name="sub" value="pulsante1" /><br/>
		<p>SELECT DISTINCT cittares FROM studenti;</p><input type=submit name="sub" value="pulsante2" /><br/>
		<p>???</p><input type=submit name="sub" value="pulsante3" /><br/>
		<p>SELECT nomec FROM corsi ORDER BY numcrediti DESC;</p><input type=submit name="sub" value="pulsante4" /><br/>
		<p>???</p><input type=submit name="sub" value="pulsante5" /><br/>
		<p>SELECT matricola,nomes,cognomes FROM studenti WHERE matricola IN (SELECT matricola FROM esami WHERE codcorso IN (SELECT codcorso FROM corsi WHERE nomec = 'Fondamenti-Inf01' OR nomec = 'Fondamenti-Inf02'))</p><input type=submit name="sub" value="pulsante6" /><br/>
	</form>
	
	<br><br><br>
</body>
</html>

<?php

	$con = pg_connect("host=localhost port=5432 user=postgres password=5C11n dbname=unimn");
	if(!$con){
		echo 'Connessione non riuscita';
	}
	
	if($sub == "pulsante1"){
		$qres = pg_query($con,"SELECT * FROM studenti");
	}else if($sub == "pulsante2"){
		$qres = pg_query($con,"SELECT DISTINCT cittares FROM studenti");
	}else if($sub == "pulsante3"){
		$qres = pg_query($con,"SELECT DISTINCT nomes FROM studenti LIKE 'R'");
	}else if($sub == "pulsante4"){
		$qres = pg_query($con,"SELECT nomec FROM corsi ORDER BY numcrediti DESC;");
	}else if($sub == "pulsante5"){
		$qres = pg_query($con,"");
	}else if($sub == "pulsante6"){
		$qres = pg_query($con,"SELECT matricola,nomes,cognomes FROM studenti WHERE matricola IN (SELECT matricola FROM esami WHERE codcorso IN (SELECT codcorso FROM corsi WHERE nomec = 'Fondamenti-Inf01' OR nomec = 'Fondamenti-Inf02'))");
	}
	
	
	if(!$qres){
		echo "Query fallita";
	}else{
		$res = pg_fetch_all($qres,PGSQL_ASSOC);
		echo "<table border=1>";
		echo "<tr>";
		for($i =0;$i<pg_num_fields($qres);$i++){
			echo "<td>";
			echo pg_field_name($qres,$i);
			echo "</td>";
		}
		echo "</tr>";
		
		foreach($res as $ar){
			echo "<tr>";
			foreach($ar as $key => $field){
				echo "<td>{$field}</td>";
			}
			echo "</tr>";
		}
		echo "</table>";
	}
	pg_close($con);

?>