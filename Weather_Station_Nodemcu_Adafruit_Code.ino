/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 01:09 AM - date 22 may 2021
 * Github Link :-- https://github.com/Zenomodiff/Weather-Station-With-Arduino-Nodemcu
 */

#include <ESP8266WiFi.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

SoftwareSerial s_serial_to_nano(2,0); 

const char *ssid =  "PASTE THE SSID";     
const char *pass =  "PASTE THE PASSWORD";
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "PASTE ADAFRUIT AIO USERNAME"
#define AIO_KEY         "PASTE ADAFRUIT AIO KEY" 

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish Smoke = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Smoke");
Adafruit_MQTT_Publish Cng = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Cng");
Adafruit_MQTT_Publish Lpg = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Lpg");
Adafruit_MQTT_Publish Air_Quality = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Air Quality");
Adafruit_MQTT_Publish Temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish Humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Humidity");
Adafruit_MQTT_Publish Ldr = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Ldr");
Adafruit_MQTT_Publish Pres = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Pressure");

// I CANNOT ADD MORE FIELDS FOR DATA PUBLISHING THAN THIS, SINCE ADAFRUIT IO HAS LIMITATIONS SO IAM HERE WITH 8 FIELDS 

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
  {    
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
 Serial.println(F("IP address: "));
 Serial.println(WiFi.localIP()); 
 digitalWrite(Wifi_Led, HIGH);

 s_serial_to_nano.begin(4800);

}

 void connect(); {
  Serial.print(F("Connecting to Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }
    if(ret >= 0)
      mqtt.disconnect();
    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}
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

 if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected());
  }
 
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

  if (! Smoke.publish(mq2_value)) {                  
      Serial.println(F("Failed"));
    } 
  if (! Cng.publish(mq4_value)) {             
      Serial.println(F("Failed"));
    }
  if (! Lpg.publish(mq5_value)) {                  
      Serial.println(F("Failed"));
    } 
  if (! Air_Quality.publish(mq135_value)) {             
      Serial.println(F("Failed"));
    }
  if (! Temperature.publish(t)) {                  
      Serial.println(F("Failed"));
    } 
  if (! Humidity.publish(h)) {             
      Serial.println(F("Failed"));
    }
  if (! Ldr.publish(ldrvalue)) {             
      Serial.println(F("Failed"));
    }
  if (! Pres.publish(Pressure)) {             
      Serial.println(F("Failed"));
    }
    
  else {
      Serial.println(F("Sent To Adafruit Dashboard !"));
    }

 while (s_serial_to_nano.available() > 0)
 s_serial_to_nano.read();

 delay (3000);

}
}
