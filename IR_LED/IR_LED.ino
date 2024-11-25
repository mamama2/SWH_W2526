/*
   Sketching mit Hardware
  DMP - SWH - WS2425
  - Demo Infrarot Fernbedienung - Üb5
  This project demonstrates how use a IR-Remote 
  to Switch on/off a LED
  
  Martinez
*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{

  Serial.begin(9600);

  pinMode (9, OUTPUT);   //An Pin 9 wird eine LED angeschlossen.

  digitalWrite(9, LOW);    //Diese soll zunächst aus sein

  irrecv.enableIRIn();

}

void loop() {

  if (irrecv.decode(&results)) {

    Serial.println(results.value, DEC);

    if (results.value == 16724175)   //Wenn der Infrarotempfänger die Zahl
      //„16724175“ ausgelesen hat (Entsprechend der Taste“1“ der Fernbedienung)


    {
      digitalWrite (9, HIGH); //soll die LED an gehen.
    }

    if (results.value == 16738455)   //Wenn der Infrarotempfänger die Zahl
      //„16718055“ ausgelesen hat (Entsprechend der Taste“2“ der Fernbedienung),

    {
      digitalWrite (9, LOW); //soll die LED aus gehen.
    }

    irrecv.resume();

  }

}
