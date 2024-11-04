
/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
- Simple LED Potentiometer Circuit
This project demonstrates how to set the brightness of a LED with a 10K POTentiometer

  Marcos Martinez
*/

//Set the LED Pin constant globally
//The LED is connected to Pin 9 of the Arduino
#define LEDPin 6 //(PWM Pin!!!)
//Connect A0 to middle pot pin
#define potPin A0

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LED Pin as an output.
    Serial.begin(9600);

  pinMode(LEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Read the voltage at the pot pin and convert to value between 0 and 255
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue);
  
  int reading = map(sensorValue,0,1023,0,255);
  Serial.println(reading);
  //Send PWM output to LED
  analogWrite(LEDPin, reading); //0..255
  delay(100);
}
