/*
DMP - Sketching mit Hardware WS2526
Changing the Blink Rate a LED using the Serial Monitor as Input
Marcos Martinez
*/

#define LED_PIN 12

int blinkDelay = 500;

int LEDState = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 4000)) {
      blinkDelay = data;
    }
  }

  if (LEDState == LOW) {
    LEDState = HIGH;
  }
  else {
    LEDState = LOW;
  }
  digitalWrite(LED_PIN, LEDState);
  delay(blinkDelay);
}
