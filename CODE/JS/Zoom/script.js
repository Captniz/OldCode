var titlesize=6;
var size = 0;

function zoom(){
    size = parseInt($(".text").css("font-size")) + 10;
    $(".text").css("font-size", size);

    $(".title").each(function(){
        if(titlesize>1){
            titlesize--;
        }
        var testo = $(this).text();

        var tag = "<h"+titlesize+" class='title'>"+testo+"</h"+titlesize+">";
        
        $(this).replaceWith(tag);
    });

    size = parseInt($(".image").css("width"))+50;
    $(".image").css("width", size + "px");

    size = parseInt($(".image").css("height"))+50;
    $(".image").css("height", size + "px");
}


function dezoom(){
    size = parseInt($(".text").css("font-size"));
    if((size-10)>=10){
        size = size - 10;
        $(".text").css("font-size", size);
    }

    $(".title").each(function(){
        if(titlesize<6){
            titlesize++;
        }
        var testo = $(this).text();

        var tag = "<h"+titlesize+" class='title'>"+testo+"</h"+titlesize+">";
        
        $(this).replaceWith(tag);
    });
    
    var width = parseInt($(".image").css("width"));
    var height = parseInt($(".image").css("height"));
    
    if((width-50)>=50 && (height-50)>=50){
        width = width - 50;
        height = height - 50;
        $(".image").css("width", width + "px");
        $(".image").css("height", height + "px");
    }

}