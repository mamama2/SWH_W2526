/*
  SKETCHING MIT HARDWARE
     DMP - WS2526
  - Demo 5 : LCD Display mit I2C Controller (One Wire)
  This project demonstrates how to measure distances
  using a ultrasonic sensor + LCD Display + I2C Controller
  WIEKER-WALZ / MARTINEZ
*/

#include<Wire.h>
#include <LCD.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int trigPin = 6;
const int echoPin = 7;
long duration;
int distance;
#define max_distance 30  // Maximum distance we want to ping for (in centimeters).

void setup()
{
  lcd.begin(16, 2); // Initializes the interface to the LCD screen
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance = duration * 0.034 / 2;

  // Prints "Distance: " on the first line of the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Draws bargraph on the second line of the LCD
  lcd.setCursor(0, 1);

  delay(500);
}
