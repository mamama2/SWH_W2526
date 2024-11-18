/*
   Sketching mit Hardware
  DMP - SWH - WS2425
  
  - Using the millis() function Termin 5
  This project demonstrates the usage of the
  millis() function in otder to avoid using delay()
 Martinez
*/
void setup() {

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH){
    digitalWrite(6, !digitalRead(6)); // Schaltet LED an pin 4 AN/AUS
  }
  digitalWrite(7, HIGH); // LED an Pin 3 AN  
  delay(1000); // Pause            
  digitalWrite(7, LOW); // LED an Pin 3 AUS    
  delay(1000); // Pause            
} 
