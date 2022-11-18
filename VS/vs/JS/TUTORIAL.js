var a = "ciao";
len = a.length;
ch = a.charAt(0);

var ran = parseInt(Math.random() * 10 + 1);

var b = [];
b[0] = 12;
b[1] = 13;
b[2] = { a: 12, b: 13 };

var c = {
  a: 12,
  b: 13,
  c: function () {
    return this.a + this.b;
  },
};

function sum(a, b) {
  return a + b;
}
res = sum(12, 13);

for (x in b) {
  console.log(x);
}

var int = "12";
int = parseInt(int);
int = parseFloat(int);

var button = document.getElementById("button");
button.value = "boh";

alert(document.forms.form1.rad.value);

alert(document.getElementById("radio1").checked);

document.writeln("Hello World");
