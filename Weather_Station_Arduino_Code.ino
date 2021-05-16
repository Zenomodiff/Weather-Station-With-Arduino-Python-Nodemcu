/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 01:04 PM - date 16 may 2021
 */
 
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "DHT.h"

#define DHTPIN 12
#define DHTTYPE DHT22
Adafruit_BMP280 bmp; 

SoftwareSerial s_serial_to_esp(3, 2);

const int mq2 = A0; 
const int mq4 = A1; 
const int mq5 = A2; 
const int mq135 = A3; 
const int rain = A6; 
float Pressure;
float Altitude;
int ldr = 11;

float m = -0.6527;  
float b = 1.30;  
float R0 = 21.91; 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  pinMode(mq2, INPUT);
  pinMode(mq4, INPUT); 
  pinMode(mq5, INPUT);
  pinMode(mq135, INPUT);
  pinMode(rain, INPUT);
  pinMode(ldr, OUTPUT); 

  Serial.begin(9600);
  
  while (!Serial) continue;
  
  s_serial_to_esp.begin(4800);

   if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
    Serial.flush();
  }

   dht.begin();
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,   
               Adafruit_BMP280::SAMPLING_X2,    
               Adafruit_BMP280::SAMPLING_X16,   
               Adafruit_BMP280::FILTER_X16, 
               Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  
  double mq2_value = analogToPPM(analogRead(mq2));
  double mq4_value = analogToPPM(analogRead(mq4));
  double mq5_value = analogToPPM(analogRead(mq5));
  double mq135_value = analogToPPM(analogRead(mq135));
  double rain_value = analogToPPM(analogRead(rain));
  int ldrvalue = analogRead(ldr);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  int f = dht.readTemperature(true);
  int pressure = (bmp.readPressure());
  Pressure = pressure;
  int altitude =  (bmp.readAltitude(1013.25)); 
  Altitude = altitude; 

  StaticJsonDocument<200> doc;
  
  doc["mq2_value"] = mq2_value;
  doc["mq4_value"] = mq4_value;
  doc["mq5_value"] = mq5_value;
  doc["mq135_value"] = mq135_value;
  doc["rain_value"] = rain_value;
  doc["t"] = t;
  doc["h"] = h;
  doc["ldrvalue"] = ldrvalue;
  doc["Pressure"] = Pressure;
  doc["Altitude"] = Altitude;

  serializeJson(doc,s_serial_to_esp);

  Serial.println("************************************");
  Serial.print("MQ-2 Smoke: ");Serial.print(mq2_value, DEC);Serial.println(" PPM");
  Serial.print("MQ-4 Cng: ");Serial.print(mq4_value, DEC);Serial.println(" PPM");
  Serial.print("MQ-5 Lpg: ");Serial.print(mq5_value, DEC);Serial.println(" PPM");
  Serial.print("MQ-135 Aiq: ");Serial.print(mq135_value, DEC);Serial.println(" PPM");
  Serial.print("RAIN Value: ");Serial.print(rain_value, DEC);Serial.println(" MM");
  Serial.print("DHT:-Temperature ");Serial.print(t);Serial.println(" C");
  Serial.print("DHT:-Humidity ");Serial.print(h);Serial.println(" %");
  Serial.print("LDR: ");Serial.print(ldrvalue, DEC); Serial.println(" LX");
  Serial.print("BMP280:-Pressure ");Serial.print(Pressure); Serial.println(" PA");
  Serial.print("BMP280:-Altitude ");Serial.print(Altitude);Serial.println(" M");
  Serial.println("************************************\n\n");

  delay(3000);
}

double analogToPPM(int aValue) {
  float sensor_volt;  
  float RS_gas;   
  float ratio; 
  int sensorValue = aValue; 

  sensor_volt = sensorValue*(5.0/1023.0); 
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; 
  ratio = RS_gas/R0;  

  double ppm_log = (log10(ratio)-b)/m; 

  return ppm_log;
}
