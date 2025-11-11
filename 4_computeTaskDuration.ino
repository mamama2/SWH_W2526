/*
DMP - Sketching mit Hardware WS2526
-Cumpute the duration of a task with Arduino
Marcos Martinez
*/
unsigned long timeBegin;

void setup() {
Serial.begin(115200);
timeBegin = millis();

}

void loop() {
  delay(1000);
unsigned long timeNow = millis();
unsigned long durationSinceStart = timeNow - timeBegin;
Serial.println(durationSinceStart);
}
