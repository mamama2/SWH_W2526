#include <ThingSpeak.h>

/*
   Sketching mit Hardware
  DMP - SWH - WS2526
  - NodeMCU ESP8266 Temperature/Humidity IoT Demo (Thingspeak)
This code send to  Thingspeak DHT22 data each 20 seconds -using wifi
Bieker-Walz / Martinez
*/
#include <DHT11.h>

//#include <DHT.h> //cargamos la librera DHT
//#define DHTPIN 1 //Seleccionamos el pin en el que se conectar el sensor
//#define DHTTYPE DHT11 //Se selecciona el DHT22(hay otros DHT)
DHT11 dht11(D4);
//DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que ser usada por Arduino para comunicarse con el sensor
#include <ESP8266WiFi.h>

unsigned long myChannelNumber = 1580381;
const char * myWriteAPIKey = "KJGBEAOA8ACDO30J";

//const char* ssid = "Vodafone-75D4_EXT";
//const char* password = "holacompi";
const char* ssid = "iPhonema3";
const char* password = "h37ryexn8nlg";
 WiFiClient  client;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
   //dht.begin(); //Se inicia el sensor

 

 
  
  
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

void loop() {
/*
float h = dht.getHumidity(); //Se lee la humedad
  float t = dht.getTemperature(); //Se lee la temperatura
  //Se imprimen las variables
  Serial.println("Humedad: "); 
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000); //Se espera 2 segundos para seguir leyendo //datos
 */
 int temperature = 0;
    int humidity = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    // Check the results of the readings.
    // If the reading is successful, print the temperature and humidity values.
    // If there are errors, print the appropriate error messages.
    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        // Print error message based on the error code.
        Serial.println(DHT11::getErrorString(result));
    }
ThingSpeak.writeField(myChannelNumber, 1, humidity, myWriteAPIKey);
  delay(2000); 
  

ThingSpeak.writeField(myChannelNumber, 2, temperature, myWriteAPIKey);
  delay(10000); 
  
  


 
   }
 
    
  
  
 
