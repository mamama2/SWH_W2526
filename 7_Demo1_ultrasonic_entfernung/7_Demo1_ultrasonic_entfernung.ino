/*
   SKETCHING MIT HARDWARE
     DMP - WS2425
   Demo 1 : Ultraschallsensor HC-SR04
  This project demonstrates how to measure distances
  using a ultrasonic sensor
  Martinez
*/

#define trigPin 6
#define echoPin 7

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 100 || distance <= 0) {
    //Serial.println("Out of range");
  }
  else {
    Serial.println(distance);
  //  Serial.println(" cm");
  }
  delay(500);
}
