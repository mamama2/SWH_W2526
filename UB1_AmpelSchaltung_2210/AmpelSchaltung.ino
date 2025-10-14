/*
   Sketching mit Hardware
  DMP - Vertiefung Medieninformatik 2- WS2526 - Sketching mit Hardware
  - Ampel Schaltung -
  Marcos Martinez
*/
int ROT = 7; //Rote LED an Pin 5
int GELB = 8; //Gelbe LED an Pin 6
int GRUN = 9; //Grüne LED an Pin 7

void setup() //Wir starten mit dem Setup

{
  pinMode(ROT, OUTPUT); // Pin 5 ist ein Ausgang.
  pinMode(GELB, OUTPUT); // Pin 6 ist ein Ausgang.
  pinMode(GRUN, OUTPUT); // Pin 7 ist ein Ausgang.
}
void loop() // Das Hauptprogramm beginnt
{
  digitalWrite(ROT, HIGH); // Schalte die LED an Pin5 an.
  delay(2000); // Warte 1000 Millisekunden.
  digitalWrite(GELB, HIGH); // Schalte die LED an Pin6 an.
  delay(1000); // Warte 1000 Millisekunden.
  digitalWrite(ROT, LOW); // Schalte die LED an Pin5 aus.
  digitalWrite(GELB, LOW); // Schalte die LED an Pin6 aus.
  digitalWrite(GRUN, HIGH); // Schalte die LED an Pin7 an.
  delay(2000); // Warte 1000 Millisekunden.
  digitalWrite(GRUN, LOW); // Schalte die LED an Pin7 aus.
  digitalWrite(GELB, HIGH); // Schalte die LED an Pin6 an.
  delay(1000); // Warte 1000 Millisekunden.
  digitalWrite(GELB, LOW); // Schalte die LED an Pin6 aus.
}
// Hier am Ende springt das Programm an den Start des Loop-Teils.
