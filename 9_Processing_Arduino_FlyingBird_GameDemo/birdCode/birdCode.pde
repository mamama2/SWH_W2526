 /*  Sketching mit Hardware WS2425
  DMP - Flappy Bird (Processing Teil)
  
  Martinez*/

import processing.serial.*;

Serial myPort;
String incomingData;
int Distance;
int IncomingDistance;

// bird height and width

float theBirdYCord = 45;
float theBirdXCord = 55;
float gravity = 5;

int speed;

Pipe pipe1 = new Pipe();
Pipe pipe2 = new Pipe();
Pipe pipe3 = new Pipe();

boolean gameOver = false;
int score = 0;
int highScore = 0;
int point = 1;

color theBirdColor = color(255, 0, 255);

void setup() {
  size(800, 600);
  pipe1.x = width + 60;
  pipe2.x = width + 240;
  pipe3.x = width + 380;

  myPort = new Serial(this, "/dev/cu.usbmodem14101", 9600);
  myPort.bufferUntil(10);
}

void serialEvent(Serial myPort) {

  incomingData = myPort.readString();
  println(incomingData);
  IncomingDistance = int (trim(incomingData));
  println("The Incoming Distance is =" +IncomingDistance);
  if (IncomingDistance > 1 && IncomingDistance <100) {
    Distance = IncomingDistance;
  }
}

void draw() {

  background(0);
  pipe1.pipe();
  pipe2.pipe();
  pipe3.pipe();

  fill (theBirdColor);
  ellipse (theBirdXCord, theBirdYCord, 40, 60);
  play();
  success(pipe1);
  success(pipe2);
  success(pipe3);
  if(IncomingDistance > 10){
    theBirdYCord -= gravity;
    
  
  }else {
  theBirdYCord += gravity;
  }
  
}

void success(Pipe test){

if (theBirdYCord < test.top || theBirdYCord > height - test.bottom){
  if(theBirdXCord > test.x && theBirdXCord < test.x + test.w){
    
    gameOver = true;
  }
}
}

void play() {

  if (gameOver == false) {
    speed = 1;
    pipe1.x -= speed;
    pipe2.x -= speed;
    pipe3.x -= speed;

    textSize(20);
    fill(255, 255, 255);
    text(score, width/2, 30);
  }
  if (gameOver == true) {

    speed = 0;
    pipe1.x -= speed;
    pipe2.x -= speed;
    pipe3.x -= speed;

    if (highScore < score) {
      highScore = score;
    }
    textSize(18);
    fill(0, 100, 150);
    textAlign(CENTER);
    text("Click PLAY again", width/2, height/2);
    text("Score: "+ score, width/2, height/2 -25 );
    text("HighScore: " +highScore, width/2, height/2 -50);

    if (mousePressed) {

      delay(800);
      score = 0;
      gameOver = false;
      theBirdXCord = 100;
      theBirdYCord = 50;
      pipe1.x = width + 60;
      pipe2.x = width + 240;
      pipe3.x = width + 380;
      pipe1.top = random(height/2);
      pipe1.bottom = random(height/2);
      pipe2.top = random(height/2);
      pipe2.bottom = random(height/2);
      pipe3.top = random(height/2);
      pipe3 .bottom = random(height/2);
    }
  }
}

class Pipe
{
  float top = random(height/3 + 210);
  float bottom = random(height/3 + 210);

  float x = width + 150;
  float w = 75;

  color pipeColor = color(0, 200, 0);


  void pipe() {
    fill(pipeColor);
    rect(x, 0, w, top);
    rect (x, height-bottom, w, bottom);

    if (x<-100) {
      score += point;
      x = width;
      top = random(height/2);
      bottom = random(height/2);
    }
  }
}
