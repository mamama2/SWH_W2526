/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
  - Simple LED Potentiometer Circuit
  This project demonstrates how to set the brightness of a LED with a 10K POTentiometer
  + Print out the values to the Serial-Console
  Marcos Martinez
*/
int ledPin = 7;
int potPin = A0;
void setup() {
  // setup pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  // initialise serial port with baud rate of 9600
  Serial.begin(9600);
}
void loop() {
  // read the value of the pot, divide it by 4, and store it as potValue
  int potValue = analogRead(potPin);
  int filteredPotValue = potValue / 4;
  // turn led on with the value of potValue
  analogWrite(ledPin, filteredPotValue);
  // print the value of the pot
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("   ");
  // print the value of the pot / 4 with a line return at the end
  Serial.print("Pot/4: ");
  Serial.println(filteredPotValue);
}
