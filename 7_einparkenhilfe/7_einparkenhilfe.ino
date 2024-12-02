/*
   SKETCHING MIT HARDWARE
     DMP - WS2425
  - Einparkenhilfe mini-Projekt
  This project demonstrates how to measure distances
  using a ultrasonic sensor
  Martinez
*/

# define LAUTSPRECHER 4
# define LED 5
# define SENDEN 6
# define ECHO 7

void setup()
{
  pinMode(SENDEN, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LAUTSPRECHER, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Funktion aufrufen
  long Entfernung = EntfernungMessen();
  // Messfehler ausschließen
  if (Entfernung < 100)
  {
    switch (Entfernung)
    {
      case 13 ... 15:
        tone(LAUTSPRECHER, 1000, 2);
        digitalWrite(LED, HIGH);
        delay(50);
        digitalWrite(LED, LOW);
        delay(500);
        break;
      case 11 ... 12:
        tone(LAUTSPRECHER, 1000, 2);
        digitalWrite(LED, HIGH);
        delay(50);
        digitalWrite(LED, LOW);
        delay(400);
        break;
      case 9 ... 10:
        tone(LAUTSPRECHER, 1000, 2);
        digitalWrite(LED, HIGH);
        delay(50);
        digitalWrite(LED, LOW);
        delay(300);
        break;

    }
  }
}
int EntfernungMessen()
{
  long Entfernung = 0;

  // Sender kurz ausschalten um Störungen des Signal zu vermeiden
  digitalWrite(SENDEN, LOW);
  delay(5);
  // Signal senden
  digitalWrite(SENDEN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN, LOW);
  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  long Zeit = pulseIn(ECHO, HIGH);
  // Entfernung in cm berechnen
  Entfernung = (Zeit / 2) * 0.03432;
  return Entfernung;
}
