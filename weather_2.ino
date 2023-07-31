#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "C:\Users\YEhar\OneDrive\Documents\Arduino\weather_2\weather_2\index_1.h" 
#include "C:\Users\YEhar\OneDrive\Documents\Arduino\weather_2\weather_2\DHT_sensor_library_for_ESPx-1.19.0\DHT_sensor_library_for_ESPx-1.19.0\DHTesp.h"
#define LED 2
#define DHTpin 14
DHTesp dht;
const char* ssid = "OnePlus Nord2 5G";
const char* password = "f6npqh9z";
ESP8266WebServer server(80);
void handleRoot() 
{
 String s = MAIN_page;
 server.send(200, "text/html", s); 
}
float humidity, temperature;
void handleADC() 
{
  int rain = analogRead(A0);
  //Create JSON data
  String data = "{\"Rain\":\""+String(rain)+"\", \"Temperature\":\""+ String(temperature) +"\", \"Humidity\":\""+ String(humidity) +"\"}";
  digitalWrite(LED,!digitalRead(LED)); 
  server.send(200, "text/plane", data); 
  delay(dht.getMinimumSamplingPeriod());
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
  Serial.print("H:");
  Serial.println(humidity);
  Serial.print("T:");
  Serial.println(temperature); //dht.toFahrenheit(temperature));
  Serial.print("R:");
  Serial.println(rain);
}
void setup()
{
  Serial.begin(115200);
  Serial.println();
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  pinMode(LED,OUTPUT); 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/readADC", handleADC); //This page is called by java Script AJAX
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
void loop()
{
  server.handleClient();          //Handle client requests
}
