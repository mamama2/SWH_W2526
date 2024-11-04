
/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
  - Alarm anlage mit Fotowiderstand und Buzzer
  This project demonstrates how to activate an alarm (Buzzer) when light reaches a certain level

  by: Marcos Martinez
*/
int FOTOZELLE = A0; // von 1 bis 10 Kohm ausprobieren 
int LED = 7;
int SensorWert;
int LAUTSPRECHER = 5;

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
  if (SensorWert < 200 )
  {
    digitalWrite(LED, HIGH);
    int ton = 200 + SensorWert / 4;
    tone(LAUTSPRECHER, ton);
  }
  else 
  {
  digitalWrite(LED, LOW);
  noTone(LAUTSPRECHER);
  }
  
  delay(10);
}
