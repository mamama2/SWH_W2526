/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
  - Simple Fotowiderstand einlesen Sketch
  This project demonstrates how to read the light intensity of the room where the arduino is
  + Print out the values to the Serial-Console
  Marcos Martinez
*/
void setup() {
  // Open Serial Communication 
  Serial.begin(9600);

}

void loop() {
  // Read light intensity. Try with different Resistor-Values, 1-10Kohm
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(100);
}
