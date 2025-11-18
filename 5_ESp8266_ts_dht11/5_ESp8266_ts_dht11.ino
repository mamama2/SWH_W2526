/*
   Sketching mit Hardware
  DMP - SWH - WS2526
  - NodeMCU ESP8266 Temperature/Humidity IoT Demo (Thingspeak)
This code send to  Thingspeak DHT22 data each 20 seconds -using wifi
Bieker-Walz / Martinez
*/

#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>


DHT dht;
unsigned long myChannelNumber = 1580381;
const char * myWriteAPIKey = "KJGBEAOA8ACDO30J";

const char* ssid = "Vodafone-75D4";
const char* password = "rb7d2kxXn2s7zyMp";

 WiFiClient  client;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(D4); 	/* D1 is used for data communication */
   // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  
  // Start the server
 // server.begin();
  //Serial.println("Server started");
   
 

  // Print the IP address
  Serial.println(WiFi.localIP());

ThingSpeak.begin(client);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod()); /* Delay of amount equal to sampling period */
  float humidity = dht.getHumidity();/* Get humidity value */
  float temperature = dht.getTemperature();/* Get temperature value */
  Serial.print(dht.getStatusString());/* Print status of communication */
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);/* Convert temperature to Fahrenheit units */
delay (1000);
ThingSpeak.writeField(myChannelNumber, 1, humidity, myWriteAPIKey);
  delay(2000); 
  

ThingSpeak.writeField(myChannelNumber, 2, dht.toFahrenheit(temperature), myWriteAPIKey);
  delay(10000); 

}