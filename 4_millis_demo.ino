/*
DMP - Sketching mit Hardware WS2526
- Learning the millis() function
Marcos Martinez
*/
void setup() {
Serial.begin(115200);
unsigned long timeBegin = millis();
delay(500);
unsigned long timeEnd = millis();

unsigned long duration = timeEnd - timeBegin;
Serial.println("The duration is: ");
Serial.println(duration);

}

void loop() {
  // put your main code here, to run repeatedly:

}
