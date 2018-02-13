console.log("here");
var button = document.querySelector("button");
var canvas = document.querySelector("canvas");
var context = canvas.getContext("2d");
var runs = 3;
var draw_interval;


document.getElementById("stopbutton").addEventListener("click", function(){
    if (draw_interval) {clearInterval(draw_interval);}
});

document.getElementById("playbutton").addEventListener("click", function(){
    draw_interval = setInterval(drawCanvas, 500);
});

function drawCanvas(){
    context.fillStyle = "white";
    context.fillRect(0, 0, 600, 600);
    console.log(runs);
    runs = runs + 1;
    context.fillStyle = "black";
    var start_x = 100;
    var start_y = 100;
    var start_side = 12345 + runs;

    for(var i = 0; i < 600; i=i+1){
        for(var j = 0; j < 600; j=j+1){
            //console.log(i);
            //console.log(j);
            var x = start_x + ((i*start_side)/100.0);
            var y = start_y + ((j*start_side)/100.0);
            c = Math.floor((x*x) + (y*y));



            if (c%2 == 0) {
                context.fillStyle = "black";
                context.fillRect(i, j, 1, 1);
            } 
            if(c%3 == 0){
                context.fillStyle = "magenta";
                context.fillRect(i, j, 1, 1);
            }
            if(c%5 == 0){
                context.fillStyle = "blue";
                context.fillRect(i, j, 1, 1);
            }
            <!-- they are ordered in increasing order so the rarer cases overrule the common -->
        }
    }

}