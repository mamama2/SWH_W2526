/*
DMP - Sketching mit Hardware WS2526
Programming Concepts - Arduino Basics
Marcos Martinez
*/
//Structs

struct joystick_reading {
  int x_position; 
  int y_position; 
  boolean isButtonPressed;
};

joystick_reading currentReading;
int reading;

void setup() {

currentReading.x_position = 125;

currentReading.y_positio/Users/marcosmartinez/Lehre/SWH_W2425/t1/1_5_ProgrammingConcepts_blink_AmpelSketches_2210/Programming_Concepts/Programming_Concepts_Looping_Switch/Programming_Concepts_Looping_Switch.inon = 225;

currentReading.isButtonPressed = false;


}

void loop() {
  // put your main code here, to run repeatedly:

}
