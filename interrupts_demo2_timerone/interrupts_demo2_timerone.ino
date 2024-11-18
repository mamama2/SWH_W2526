/*
   Sketching mit Hardware
  DMP - SWH - WS2425
  - TimerOne Lib Interrupts. Termin 5
 
  This project demonstrates the usage of interrupts using the timerOne Library

  by: Marcos Martinez
  */
#include <TimerOne.h>

int ledPin = 13;
volatile int ledState = HIGH;

void setup()
{
  pinMode(13, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(toggleLED); 
}

void loop(){
}

void toggleLED()
{
  digitalWrite(ledPin, ledState);
  ledState = !ledState; 
}
