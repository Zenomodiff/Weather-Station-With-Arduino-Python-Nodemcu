/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 08:07pm - date 16 may 2021
 * Github Link :-- https://github.com/Zenomodiff/Weather-Station-With-Arduino-Python-Nodemcu
 */

#include <ESP8266WiFi.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h> 

SoftwareSerial s_serial_to_nano(2,0); 

String apiKey = "PASTE THE THINGSPEAK API KEY";     
 const char *ssid =  "TYPE THE SSID"; 
const char *pass =  "TYPE THE PASSWORD";
const char* server = "api.thingspeak.com";

WiFiClient client;

float mq2_value_global;
float mq4_value_global;
float mq5_value_globak;
float mq135_value_global;
float rain_value_global;
float t_global;
float h_global;
float ldr_value_global;
float Pressure_global;
float Altitude_global;

int Wifi_Led = 14;

void setup() {

  Serial.begin(9600);
      
  Serial.println("-------------------------");
  Serial.println(" Weather Station  ");
  Serial.println("-------------------------");

  pinMode(Wifi_Led, OUTPUT);
  digitalWrite(Wifi_Led, LOW);

 Serial.println("Connecting to ");
 Serial.println(ssid); 
 
 WiFi.begin(ssid, pass); 
 while (WiFi.status() != WL_CONNECTED) 
 { 
  delay(500);
  Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected"); 
 digitalWrite(Wifi_Led, HIGH);
 s_serial_to_nano.begin(4800);

}

void loop() {
  
  if (s_serial_to_nano.available()) {
  DynamicJsonDocument doc(1024);
  DeserializationError err = deserializeJson(doc, s_serial_to_nano);
  if (err == DeserializationError::Ok) {

float mq2_value = doc["mq2_value"];
float mq4_value = doc["mq4_value"];
float mq5_value = doc["mq5_value"];
float mq135_value = doc["mq135_value"];
float rain_value = doc["rain_value"];
float t = doc["t"];
float h = doc["h"];
int ldrvalue = doc["ldrvalue"];
int Pressure = doc["Pressure"];
int Altitude = doc["Altitude"];

 
 Serial.println();
 Serial.print("1. Smoke ");Serial.print(mq2_value);Serial.println(" PPM");
 Serial.print("2. cng ");Serial.print(mq4_value);Serial.println(" PPM");
 Serial.print("3. lpg ");Serial.print(mq5_value);Serial.println("PPM");
 Serial.print("4. airquality ");Serial.print(mq135_value);Serial.println(" PPM");
 Serial.print("5. rainvalue ");Serial.print(rain_value);Serial.println(" MM");
 Serial.print("6. temperature ");Serial.print(t);Serial.println(" C");
 Serial.print("7. humidity ");Serial.print(h);Serial.println(" %");
 Serial.print("8. ldr ");Serial.print(ldrvalue);Serial.println(" LX");
 Serial.print("9. Pressure ");Serial.print(Pressure);Serial.println(" PA");
 Serial.print("10. Altitude ");Serial.print(Altitude);Serial.println(" M");
 Serial.println();

 while (s_serial_to_nano.available() > 0)
 s_serial_to_nano.read();
if (client.connect(server,80)) 
{  
                            
String postStr = apiKey;
postStr +="&field1=";
postStr += String(mq2_value);
postStr +="&field2=";
postStr += String(mq4_value);
postStr +="&field3=";
postStr += String(mq5_value);
postStr +="&field4=";
postStr += String(mq135_value);
postStr +="&field5=";
postStr += String(t);
postStr +="&field6=";
postStr += String(h);
postStr +="&field7=";
postStr += String(Pressure);
postStr +="&field8";
postStr += String(Altitude);
postStr += "\r\n\r\n/r/n/r/n/r/n/r/n/r/n/r/n";
 
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n\n\n\n\n\n\n");
client.print(postStr);
Serial.println("%. Send to Thingspeak.");
}
client.stop();
Serial.println("Waiting...");
delay(30000);

}
}
}
