var size = 400;
var canvas = document.createElement('canvas');
canvas.width = size;
canvas.height = size;
document.body.insertBefore(canvas, document.body.childNodes[0]);
var context = canvas.getContext("2d");

// input variables
var fidelity = 35; // you can go higher, but you need to add more coloring too
var count = 0;

// framing the screen on the function
var start_x = size/1.4;
var start_y = size/2;
var scale = size/2.2;


for(var j=0; j<size; j++){
    for(var k=0; k<size; k++){
	count = 0;
	var ca = (j - start_x) / scale;
	var cb = (k - start_y) / scale;
	var zx = 0.; 
	var zy = 0.; 

	// see how many counts it takes to calculate
	while(count <= fidelity && (zx*zx + zy*zy <= 4)){//((Math.pow(zx, 2) + Math.pow(zy, 2)) <= 4)){
	    count++;
	    xtemp = zx*zx - zy*zy; // complex x temporary
	    zy = 2. * zx * zy + cb;
	    zx = xtemp + ca;
	}

	// color based on number of counts 
	if(count <= 20 && count >= 18) {
	    context.fillStyle = "rgba(255, 55, 101, .9)";
	} else if(count >=30 && count <= 35){
	    context.fillStyle = "rgba(20, 250, 255, .9)";
	}else {
	    context.fillStyle = "rgba(0.0, 0.0, 0.0, "+(count / fidelity)+")";
	}
	context.fillRect(j, k, 1, 1);
    }
}

