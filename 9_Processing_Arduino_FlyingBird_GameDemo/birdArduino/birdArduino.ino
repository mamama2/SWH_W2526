/*   Sketching mit Hardware
  DMP - WS2425
  
  Martinez*/
const int trigPin = 6;
const int echoPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code her/e, to run repeatedly:
  unsigned int duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(6);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = microToCm(duration);
  long inch = cm / 2.54;
  Serial.println(cm);

}

long microToCm(long microSeconds) {

  return microSeconds / 29 / 2;
}
