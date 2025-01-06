/***********************************************************
File name:   demo1_ard_btn_led
Description: Arduino and processing Kommunikation

SWH WS2425 / DMP / Uebung Nr.9
Martinez
***********************************************************/
int led = 8;
int button = 2;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char ledState = Serial.read();
    if (ledState == '1') {
      digitalWrite(led, HIGH);
    }
    if (ledState == '0') {
      digitalWrite(led, LOW);
    }
  }
  int buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    Serial.println("Button is pressed");
    delay(500);
  }
}
