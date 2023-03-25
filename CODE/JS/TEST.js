var v = new Array(10);
var str = "";
var ctr = 0;

for (var i = 0; i < 10; i++) {
  v[i] = new Array(10);
}

for (var i = 0; i < 10; i++) {
  for (var j = 0; j < 10; j++) {
    v[i][j] = parseInt(Math.random() * 2 + 0);
  }
}

for (var i = 0; i < 10; i++) {
  str += "<tr>";
  for (var j = 0; j < 10; j++) {
    str += "<td onclick='clic(this.id)' id='";
    str += ctr;
    str += "'>";
    str += "</td>";
    ctr++;
  }
  str += "</tr>";
}

document.getElementById("table").innerHTML = str;

function clic(id) {
  var x = parseInt(id / 10);
  var y = id % 10;
  if (v[x][y] == 1) {
    document.getElementById(id).style.backgroundColor = "green";
  }
}