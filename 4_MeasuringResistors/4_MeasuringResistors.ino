
/*
   Sketching mit Hardware
  DMP - Sketching mit Hardware - WS24_25
- Simple Sketch to find out the value of a Resistor(Widerstand)
This project demonstrates how to set the brightness of a LED with a 10K POTentiometer

by: Marcos Martinez
*/

int analogPin= A1;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 2000;
float R2= 0;
float buffer= 0;

void setup()
{
Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
Serial.print("Spannung Out(V): ");
Serial.println(Vout);
Serial.print("Wiederstand_R2(Ohms): ");
Serial.println(R2);
delay(2000);
}
}
