/*
Realizzare sito HTML+CSS+JS che realizzi una rubrica telefonica
per memorizzare le seguenti informazioni : Nome, Cognome, Num. Telefonico
Il sito si presentera' come una sola pagina divisa in quattro sezioni

Navbar (in alto)
che permette di selezionare le Form : Inserisci, Modifica, Cancella, Cerca

Form (Sottostante la Navbar)
dove, in base alla selezione della Navbar,
verranno visualizzate le Form corrispondenti per : Inserisci, Modifica, Cancella, Cerca

Visualizzazioni (sottostante la Form)
Dove verra' mostrato
-l'esito delle operazioni di : Inserisci, Modifica , Cancella
-l'elenco dei risultati di : Cerca

Footer (in basso)
con il vostro nome cognome ed email
*/

var dati = [];
var showed = document.getElementById("ins");

function setInsert() {
  showed.style.display = "none";
  showed = document.getElementById("ins");
  showed.style.display = "block";
}
function setModify() {
  showed.style.display = "none";
  showed = document.getElementById("mod");
  showed.style.display = "block";
}
function setDelete() {
  showed.style.display = "none";
  showed = document.getElementById("del");
  showed.style.display = "block";
}
function setFind() {
  showed.style.display = "none";
  showed = document.getElementById("src");
  showed.style.display = "block";
}

function insert() {
  var tmp = {
    nome: showed.getElementById("nome").value,
    cnome: showed.getElementById("cnome").value,
    num: showed.getElementById("num").value,
  };
  alert(showed.getElementById("nome").value);
  showed.reset();
  dati.push(tmp);
}
function find() {
  str = showed.getElementById("cnome").value;
  for (x in dati) {
    if (dati[x].cnome == str) {
      selected = dati[x];
      showed.getElementById("cnome").value = "trovato";
      break;
    }
  }
}

//TODO: non ho voglia di fare il resto
