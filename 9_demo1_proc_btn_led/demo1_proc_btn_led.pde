/***********************************************************
File name:   demo1_ard_btn_led
Description: Arduino and processing Kommunikation

SWH WS2425 / DMP / Uebung Nr.9
Martinez
***********************************************************/
import processing.serial.*;

Serial myPort;
String myText="";

void setup(){
size(300, 300);
myPort = new Serial(this, "/dev/cu.usbmodem14101", 9600);
myPort.bufferUntil('n');
}
void serialEvent (Serial myPort){
myText = myPort.readStringUntil('n');
}

void draw(){
background(0,0,0);
text(myText, 120, 120);
myText="";

if(mousePressed && (mouseButton == LEFT)){
myPort.write('1');
}
if (mousePressed && (mouseButton == RIGHT)){
myPort.write('0');
}
}
