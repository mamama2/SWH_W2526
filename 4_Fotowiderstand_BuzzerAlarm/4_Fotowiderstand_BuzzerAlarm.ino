
/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
  - Alarm anlage mit Fotowiderstand und Buzzer
  This project demonstrates how to activate an alarm (Buzzer) when light reaches a certain level

  by: Marcos Martinez
*/

#include "NewToneLib.h"
MyTone t(false);

#define LAUTSPRECHER 5 
int FOTOZELLE = A1; // von 1 bis 10 Kohm ausprobieren 
int LED = 6;
int SensorWert;
//int LAUTSPRECHER = 5;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(LAUTSPRECHER, OUTPUT);
}
void loop()
{
  SensorWert = analogRead(FOTOZELLE);
  Serial.print("Ausgelesener Wert: ");
  Serial.println(SensorWert);

  /*
    Der Wert muss der aktuellen Helligkeit
    entsprechend angepasst werden
    → seriellen Monitor aufrufen
  */
  if (SensorWert < 500 )
  {
    digitalWrite(LED, HIGH);
    int ton = 300 + SensorWert / 4;
    t.tone(LAUTSPRECHER, ton, 500);
    delay(100);
  }
  else 
  {
  digitalWrite(LED, LOW);
  
  //noTone(LAUTSPRECHER);
  }
  
  delay(10);
}
