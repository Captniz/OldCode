function Insert(path) {
    //retrieve the text from the file in the path and insert it into the div with id "text"
    var text = document.getElementById("text");
    var file = new File(path);
    file.open("r");
    text.innerHTML = file.read();
    file.close();
}
