/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 01:04 PM - date 16 may 2021
 * Github Link :-- https://github.com/Zenomodiff/Weather-Station-With-Arduino-Python-Nodemcu
 */

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h> 

SoftwareSerial s_serial_to_nano(2,0); 

#define FIREBASE_HOST "PASTE THE FIREBASE HOST NAME"
#define FIREBASE_AUTH "PASTE THE FIREBASE AUTH KEY"
const char *ssid =  "TYPE THE SSID ";     
const char *pass =  "TYPE THE PASSWORD";

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
 Serial.println("IP address: "); Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 digitalWrite(Wifi_Led, HIGH);
 s_serial_to_nano.begin(4800);

}

void loop() {
  
  if (s_serial_to_nano.available()) {
 DynamicJsonBuffer jsonBuffer(1024); 
 JsonObject& root = jsonBuffer.parseObject(s_serial_to_nano);
if(!root.success()){
  return;
}
JsonArray& data = root["data"];


float mq2_value = root["mq2_value"];
float mq4_value = root["mq4_value"];
float mq5_value = root["mq5_value"];
float mq135_value = root["mq135_value"];
float rain_value = root["rain_value"];
float t = root["t"];
float h = root["h"];
int ldrvalue = root["ldrvalue"];
int Pressure = root["Pressure"];
int Altitude = root["Altitude"];

 
 Serial.println();
 Serial.print("1. Smoke ");Serial.print(mq2_value);Serial.println(" PPM");
 Serial.print("2. Cng ");Serial.print(mq4_value);Serial.println(" PPM");
 Serial.print("3. Lpg ");Serial.print(mq5_value);Serial.println("PPM");
 Serial.print("4. Air_Quality ");Serial.print(mq135_value);Serial.println(" PPM");
 Serial.print("5. Rain_Value ");Serial.print(rain_value);Serial.println(" MM");
 Serial.print("6. Temperature ");Serial.print(t);Serial.println(" C");
 Serial.print("7. Humidity ");Serial.print(h);Serial.println(" %");
 Serial.print("8. Ldr ");Serial.print(ldrvalue);Serial.println(" LX");
 Serial.print("9. Pressure ");Serial.print(Pressure);Serial.println(" PA");
 Serial.print("10. Altitude ");Serial.print(Altitude);Serial.println(" M");
 Serial.println();

  Firebase.setFloat ("Smoke",mq2_value);
  Firebase.setFloat ("Cng",mq4_value);
  Firebase.setFloat ("Lpg",mq5_value);
  Firebase.setFloat ("Air_Quality",mq135_value);
  Firebase.setFloat ("Rain_Value",rain_value);
  Firebase.setFloat ("Temperature",t);
  Firebase.setFloat ("Humidity",h);
  Firebase.setFloat ("Ldr",ldrvalue);
  Firebase.setFloat ("Pressure",Pressure);
  Firebase.setFloat ("Altitude",Altitude);
  delay(200);
  
 while (s_serial_to_nano.available() > 0)
 s_serial_to_nano.read();
 if(Firebase.failed())
{
  Serial.println("Firebase log sending failed");
  Serial.println(Firebase.error());
  return;
}

}
}
