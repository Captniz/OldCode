//GLOBAL VARS
var reqtype = "";
const socket = new WebSocket("ws://localhost:5567");
var infos = [];

//MAIN
request("#LIST GROUP");


//EVENTS
socket.onopen = function(event) {
    console.log("Connected to server");
};

socket.onmessage = function(event) {
    //TODO: parse the message or switch to http requests
}

window.onbeforeunload = function(e){
    socket.send("#EXIT");
    socket.close();
};

//FUNCS
void function request(req){
    socket.send(req);
    reqtype = req;
}