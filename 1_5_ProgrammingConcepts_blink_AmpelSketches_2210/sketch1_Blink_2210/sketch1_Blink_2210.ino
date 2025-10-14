/*
 * Sketching mit Hardware
DMP - Vertiefung Medieninformatik 2 - WS2526 - Sketching mit Hardware 

- Simple LED Circuit
how an LED can be controlled by the Arduino

Marcos Martinez
*/

//Set the LED Pin constant globally
//The LED is connected to Pin 8 of the Arduino
#define LEDPin 13


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LED Pin as an output.
  pinMode(LEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Turn the LED On
  digitalWrite(LEDPin, HIGH);
  //Wait 1 second
  delay(100);
  //Turn the LED Off
  digitalWrite(LEDPin, LOW);
  //Wait 1 second
  delay(100);
}
