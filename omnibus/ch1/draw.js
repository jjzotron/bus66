var context = document.querySelector("canvas").getContext("2d");
var seed = 12345;

document.getElementById("generate").addEventListener("click", function(){
    drawCanvas(seed++);
});

function drawCanvas(){
    context.fillStyle = "white";
    context.fillRect(0, 0, 600, 600);
    context.fillStyle = "black";
    var start_x = 100;
    var start_y = 100;
    var start_side = seed;
    var c = 0;

    for(var i = 0; i < 600; i=i+1){
        for(var j = 0; j < 600; j=j+1){
            var x = start_x + ((i*start_side)/100.0);
            var y = start_y + ((j*start_side)/100.0);
            c = Math.floor((x*x) + (y*y));
            // they are ordered in increasing order so the rarer cases overrule the common
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
        }
    }
}
