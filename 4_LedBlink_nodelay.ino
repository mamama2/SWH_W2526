/*
DMP - Sketching mit Hardware WS2526
-LED Blink without the delay() function
Marcos Martinez
*/
#define LED1_PIN 12

unsigned long previousLED1Blink = millis();
unsigned long intervalLED1Blink = 500;

int LED1State = LOW;

void setup() {
pinMode(LED1_PIN, OUTPUT);
}

void loop() {
unsigned long timeNow = millis();
if (timeNow - previousLED1Blink > intervalLED1Blink){
  if (LED1State == LOW){
    LED1State = HIGH;
  }else {
    LED1State = LOW;
  }
  digitalWrite(LED1_PIN, LED1State);
  previousLED1Blink += intervalLED1Blink;
}

}
