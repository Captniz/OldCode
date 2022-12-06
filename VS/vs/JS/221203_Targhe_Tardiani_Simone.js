var activeId = "nuova";

function Show(id) {
  document.getElementById(activeId).style.display = "none";
  activeId = id;
  document.getElementById(activeId).style.display = "block";
}

function Nuova() {
  var nome = document.forms.nuovaF.getElementById("nome").value;
  var cnome = document.forms.nuovaF.getElementById("cognome").value;
  var indirizzo = document.forms.nuovaF.getElementById("indirizzo").value; 
  var citta = document.forms.nuovaF.getElementById("citta").value;
  var data 
}
