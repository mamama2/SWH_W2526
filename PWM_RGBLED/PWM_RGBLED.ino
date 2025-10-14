/*
DMP - Sketching mit Hardware WS2526
-Eine LED pulsieren lassen
Marcos Martinez
*/
int LED=9; //Das Wort „LED“ steht jetzt für den Wert 9.
int helligkeit= 0; //Das Wort „helligkeit“ steht nun für den Wert, der bei der PWM ausgegeben wird. Die Zahl 0 ist dabei nur ein beliebiger Startwert.
int fadeschritte= 4; //fadeschritte: bestimmt die Geschwindigkeit des „fadens“.

void setup()//Hier beginnt das Setup.
{
  Serial.begin(9600);
pinMode(LED, OUTPUT);//Der Pin mit der LED (Pin9) ist ein Ausgang
}
void loop()
{
 // Serial.println(fadeschritte);
analogWrite(LED, helligkeit);//Mit der Funktion analogWrite wird hier an dem Pin mit der LED (Pin9) die PWM Ausgabe aktiviert. Der PWM-Wert ist der Wert, der unter dem Namen „helligkeit“ gespeichert ist. In diesem Fall „0“ (Siehe ersten Programmabschnitt)
helligkeit = helligkeit + fadeschritte; //Nun wird der Wert für die PWM-Ausgabe verändert. Unter dem Wert „helligkeit“ wird jetzt zur vorherigen helligkeit der Wert für die fadeschritte addiert. In diesem Fall: helligkeit=0+ 5. Der neue Wert für „helligkeit“ ist also nicht mehr 0 sondern 5. Sobald der Loop-Teil einmal durchgelaufen ist, wiederholt er sich. Dann beträgt der Wert für die Helligkeit 10. Im nächsten Durchlauf 15 usw. usw…
Serial.println(helligkeit);
delay(25);//Die LED soll für 25ms (Millisekunden), also nur ganz kurz die Helligkeit beibehalten. Verringert man diesen Wert, wird das Pulsieren ebenfalls schneller.
if (helligkeit == 0 || helligkeit == 255) //Bedeutung des Befehls: Wenn die Helligkeit den Wert 0 ODER 255 erreicht hat, wechselt der Wert für die „fadeschritte“ von positiv zu negativ bzw. andersrum. Grund: Die LED wird zunächst bei jedem Durchlauf des Loop-Teils immer ein bisschen heller. Allerdings ist irgendwann der Maximalwert für die PWM-Ausgabe mit dem Wert 255 erreicht. Die LED soll dann wieder Schritt für Schritt dunkler werden. Also wird der Wert für die „fadeschritte“ an dieser Stelle negativiert (Ein Minuszeichen wird davor gesetzt).
{
fadeschritte = -fadeschritte ; //Das bedeutet für den nächsten Durchlauf, dass in der Zeile „helligkeit = helligkeit + fadeschritte;“ die helligkeit abnimmt. Beispiel: „helligkeit=255+(-5)“. Der Wert für Helligkeit ist ab dann 250. Im nächsten Durchlauf 245 usw. usw… Sobald der Wert für Helligkeit bei 0 angekommen ist, wechselt wieder das Vorzeichen. (Man bedenke die alte mathematische Regel: „minus und minus ergibt plus“.)
  Serial.println(fadeschritte);
}
else {
}
}//Mit dieser letzten Klammer wird der Loop-Teil geschlossen.
