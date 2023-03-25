var modello = "";
var marca = "";
var alim = "";
var colore = "";

function setup() {
  modello = document.getElementById("modello").value;
  marca = document.forms.marc.marca.value;
  alim = document.forms.alime.alim.value;
  colore = document.forms.colore.color.value;

  var str = "";
  str = modello + " " + marca + " " + alim + " " + colore;
  document.getElementById("vis").innerHTML = str;
}
