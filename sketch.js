let drawingMode = 0;

function setup() {
  createCanvas(windowWidth, windowHeight);
  background(230, 230, 230);
}

function draw() {
  
  if (drawingMode == 1) {
    // let diameter = random(30);
    let diameter = 20;
    circle(mouseX, mouseY, diameter);  
  }
  
}

function keyTyped() {
  if (key == 'd') {
    if (drawingMode == 0) {
      drawingMode = 1;
    } else {
      drawingMode = 0;
    }
  }
}