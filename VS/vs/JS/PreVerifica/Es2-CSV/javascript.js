//get file 
$("#file").files[0];
var reader = new FileReader();
reader.readAsText(file);
reader.onload = function() {
    var csv = reader.result;
    var lines = csv.split(" ");
    var result = [];
    var headers = lines[0].split(",");
    for(var i=1;i<lines.length;i++){
        var obj = {};
        var currentline=lines[i].split(",");
        for(var j=0;j<headers.length;j++){
            obj[headers[j]] = currentline[j];
        }
        result.push(obj);
    }
}