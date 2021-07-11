/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 10:12 PM - date 11 july 2021
 * Github Link :-- https://github.com/Zenomodiff/Weather-Station-With-Arduino-Python-Nodemcu
 */

#include <ESP8266WiFi.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial s_serial_to_nano(2,0); 

const char *ssid =  "TYPE THE SSID"; 
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

  Serial.begin(115200);
  lcd.begin();
      
  Serial.println("-------------------------");
  Serial.println(" Weather Station  ");
  Serial.println("-------------------------");

  pinMode(Wifi_Led, OUTPUT);
  digitalWrite(Wifi_Led, LOW);

  lcd.print("Data From");
  lcd.setCursor(0,1);
  lcd.print("Arduino Nano");
  delay(2000);
  lcd.clear();

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
 
  lcd.clear();
  lcd.print("Smoke");
  lcd.setCursor(0,1);
  lcd.print(mq2_value);
  delay(3000);

  lcd.clear();
  lcd.print("Cng");
  lcd.setCursor(0,1);
  lcd.print(mq4_value);
  delay(3000);

  lcd.clear();
  lcd.print("Lpg");
  lcd.setCursor(0,1);
  lcd.print(mq5_value);
  delay(3000);

  lcd.clear();
  lcd.print("Air-Quality");
  lcd.setCursor(0,1);
  lcd.print(mq135_value);
  delay(3000);

  lcd.clear();
  lcd.print("Rain-Value");
  lcd.setCursor(0,1);
  lcd.print(rain_value);
  delay(3000);

  lcd.clear();
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.print(t);
  delay(3000);

  lcd.clear();
  lcd.print("Humidity");
  lcd.setCursor(0,1);
  lcd.print(h);
  delay(3000);

  lcd.clear();
  lcd.print("Ldr");
  lcd.setCursor(0,1);
  lcd.print(ldrvalue);
  delay(3000);

  lcd.clear();
  lcd.print("Altitude");
  lcd.setCursor(0,1);
  lcd.print(Altitude);
  delay(3000);

  lcd.clear();
  lcd.print("Pressure");
  lcd.setCursor(0,1);
  lcd.print(Pressure);
  delay(3000);

 while (s_serial_to_nano.available() > 0)
 s_serial_to_nano.read();

}
}
