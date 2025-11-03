/*
   Sketching mit Hardware
  DMP - SWH - WS2526
  - Debounce a pushbutton. Termin 5
 
  This project demonstrates how to debounce a pushbutton and avoid unexpected results
 BIEKER-WALZ / MARTINEZ
*/
/*
#define BUTTON_PIN 2
int buttonPress = 0;
void setup() {
  Serial.begin(9660);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonPress = digitalRead(BUTTON_PIN);

  if (buttonPress == 1) {
    Serial.println("BANG!");
  }
}
*/


#define BUTTON_PIN 2
int buttonPress = 0;

unsigned long  lastTimeButtonChanged = millis();
unsigned long  debounceDuration = 100; // millis()

void setup() {
  Serial.begin(9660);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (millis() - lastTimeButtonChanged > debounceDuration) {

  
    buttonPress = digitalRead(BUTTON_PIN);

    if (buttonPress == 1) {
      lastTimeButtonChanged = millis();
      Serial.println("BANG!");
      //delay(100);
    }
  }
}

