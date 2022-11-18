var v = new Array(20);
var ctr = 0;
var doc = document.getElementById("table").innerHTML;

for (var i = 0; i < v.length; i++) {
  v[i] = new Array(20);
}

for (var i = 0; i < 20; i++) {
  for (var j = 0; j < 20; j++) {
    v[i][j] = parseInt(Math.random() * 51 + 100);
  }
}

var str = "";
for (var i = 0; i < 20; i++) {
  str += "<tr>";
  ctr = 0;
  for (var j = 0; j < 20; j++) {
    str += "<td>";
    str += v[i][j];
    str += "</td>";
    ctr += v[i][j];
  }
  if (ctr > 2500) {
    str += "<td style='background-color:red'>";
  } else {
    str += "<td>";
  }
  str += ctr;
  str += "</td>";
  str += "</tr>";
}

str += "<tr>";
for (var i = 0; i < 20; i++) {
  ctr = 0;
  for (var j = 0; j < 20; j++) {
    ctr += v[i][j];
  }
  if (ctr > 2500) {
    str += "<td style='background-color:red'>";
  } else {
    str += "<td>";
  }
  str += ctr;
  str += "</td>";
}
str += "</tr>";

document.getElementById("table").innerHTML = str;
