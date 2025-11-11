/*
   Sketching mit Hardware
  DMP - SWH - WS2526
  - TimerOne Lib Interrupts. Termin 5
 
  This project demonstrates the usage of interrupts using the timerOne Library

  by: Marcos Martinez
  */
#include <TimerOne.h>

int ledPin = 11;
volatile int ledState = HIGH;

void setup()
{
  pinMode(11, OUTPUT);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(toggleLED); 
}

void loop(){
}

void toggleLED()
{
  digitalWrite(ledPin, ledState);
  ledState = !ledState; 
}