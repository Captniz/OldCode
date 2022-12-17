var DIM = 20;
var PROB = 2;
var ctrTrovati = 0;
var ctrDaTrovare = 0;

var campo = new Array(DIM);
for (var i = 0; i < DIM; i++) {
  campo[i] = new Array(DIM);
}
alert(campo);
for (var i = 0; i < DIM; i++) {
  for (var j = 0; j < DIM; j++) {
    campo[i][j] = parseInt(((Math.random() * 10) % 10) + 1);
    if (campo[i][j] <= PROB) {
      campo[i][j] = 1;
    } else {
      campo[i][j] = 0;
      ctrTrovati += 1;
    }
  }
}
alert(campo);
var str = "";
var ctr = 0;
for (var i = 0; i < DIM; i++) {
  str += "<tr>";
  for (var j = 0; j < DIM; j++) {
    str += "<td>";
    str +=
      "<input type='button' value='' id='" +
      ctr +
      "' onclick='showValue(" +
      i +
      "," +
      j +
      ",this.id)' />";
    str += "</td>";
    ctr++;
  }
  str += "</tr>";
}
document.getElementById("campo").innerHTML = str;

function checkSurrounding(x, y) {
  var ctr = 0;
  for (var i = x - 1; i < x + 1; i++) {
    for (var j = y - 1; j < y + 1; j++) {
      if (campo[i][j] != undefined) {
        if (campo[i][j] == 1) {
          ctr++;
        }
      }
    }
  }
  return ctr;
}

function showValue(x, y, id) {
  if (campo[x][y] == 0) {
    alert(checkSurrounding(x, y));
    var doc = (document.getElementById(id).value = checkSurrounding(x, y));
    ctrDaTrovare++;
    if (ctrDaTrovare == ctrTrovati) {
      document.getElementById("titolo").innerHTML = "HAI VINTO";
    }
  } else {
    //SCIOPA
    document.getElementById(id).value = "B";
    document.getElementById("titolo").innerHTML = "SEI ESPLOSO XD";
  }
}

/*SERVE :
Un titolo, tag titolo;
Una table, tag campo;
*/
