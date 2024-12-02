 
/*
   SKETCHING MIT HARDWARE
     DMP - WS2425
   DEMO 6:Improve Ultrsonic nodelay() + LCD
 Martinez
*/
#include <LiquidCrystal.h> // include the library code: !
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define ECHO_PIN 7
#define TRIGGER_PIN 6

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;

void triggerUltrasonicSensor()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance()
{
  unsigned long timeBegin = micros();
  double durationMicros = pulseIn(ECHO_PIN, HIGH);
  unsigned long timeEnd = micros();
  unsigned long codeDuration = timeEnd - timeBegin;
 // Serial.print("Duration :");
 // Serial.println(codeDuration);
  double distance = durationMicros / 58.0; // cm (148.0: inches)
  return distance;
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
}

void loop() {
  int dist;
  unsigned long timeNow = millis();
  
  if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
    triggerUltrasonicSensor();
   // dist = int(getUltrasonicDistance());
    //Serial.println(((int)(getUltrasonicDistance() * 100 ))/ 100.0);+
    Serial.println(getUltrasonicDistance());
     lcd.setCursor(0, 0);
    // lcd.print(getUltrasonicDistance()); // print the number of seconds since reset:

  }
}
