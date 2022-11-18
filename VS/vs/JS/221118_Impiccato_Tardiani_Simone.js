var vite = 5;
var corrects = 0;
var words = {
  1: "CIAO",
  2: "CASA",
  3: "CANE",
  4: "GATTO",
  5: "MELA",
  6: "PALLA",
};

document.getElementById("vite").innerHTML = vite;
var word = words[parseInt(((Math.random() * 10) % 6) + 1)];
hidWord = Array(word.length).fill("_");

document.getElementById("parola").innerHTML = hidWord.join(" ");

function Activate(id) {
  var letter = document.getElementById(id).value;
  var correct = false;
  for (var i = 0; i < word.length; i++) {
    alert(word.charAt(i));
    alert(letter);
    if (word.charAt(i) == letter) {
      hidWord[i] = letter;
      corrects++;
      correct = true;
    }
  }
  if (correct == true) {
    document.getElementById(id).style.backgroundColor = "green";
  } else {
    document.getElementById(id).style.backgroundColor = "red";
    vite--;
  }
  document.getElementById("vite").innerHTML = vite;
  document.getElementById("parola").innerHTML = hidWord.join(" ");

  if (vite == 0) {
    document.getElementById("parola").innerHTML = word;
    document.getElementById("vite").innerHTML = "Hai perso";
    for (var i = 1; i < 27; i++) {
      document.getElementById(i).disabled = true;
    }
  } else if (corrects == word.length) {
    document.getElementById("parola").innerHTML = word;
    document.getElementById("vite").innerHTML = "Hai vinto";
    for (var i = 1; i < 27; i++) {
      document.getElementById(i).disabled = true;
    }
  }
  return;
}
