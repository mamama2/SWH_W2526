/*
DMP - Sketching mit Hardware WS2526
-avoid the delay() function.
Marcos Martinez
*/
unsigned long previousTime = millis();
unsigned long interval = 500;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - previousTime > interval) {
    Serial.println("Hello");
    Serial.println(millis());
    //previousTime = timeNow;
    previousTime += interval;

  }
}
