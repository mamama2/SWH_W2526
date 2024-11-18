
/*
   Sketching mit Hardware
  DMP - SWH - WS2425
  - Demo nodelay() Blink LED. Termin 5
  This project demonstrates how to avoid using the delay function

  by: Marcos Martinez
*/
const int ledPin =  6;
int ledState = LOW;
long myTimer = 0;
long myTimeout = 100;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (millis() > myTimeout + myTimer ) {
    myTimer = millis();
    if (ledState == LOW) ledState = HIGH;
    else ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}