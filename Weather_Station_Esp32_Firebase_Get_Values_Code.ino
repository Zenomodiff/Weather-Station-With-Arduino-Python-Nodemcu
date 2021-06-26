/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 12:18 AM - date 27 june 2021
 * Github Link :-- https://github.com/Zenomodiff/Weather-Station-With-Arduino-Nodemcu
 */

#include <IOXhop_FirebaseESP32.h>
#include <WiFi.h>

#define FIREBASE_HOST "PASTE THE FIREBASE HOST URL" 
#define FIREBASE_AUTH "PASTE THE FIREBASE AUTH TOKEN"  
#define ssid "PASTE THE WIFI SSID"  
#define pass "PASTE THE WIFI PASSWORD"

int air_quality;
int altitude;
int cng;
int humidity;
int ldr;
int lpg;
int pressure;
int rain_value;
int smoke;
int temperature;


void setup()
{
    Serial.begin(115200);
    delay(1000);

    WiFi.begin(ssid, pass); 

 Serial.println("Connecting to ");
 Serial.println(ssid); 
 
 WiFi.begin(ssid, pass); 
 while (WiFi.status() != WL_CONNECTED) 
 { 
  delay(500);
  Serial.print(".");
 }

    Serial.println();
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP Address is : ");
    Serial.println(WiFi.localIP()); 

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}

void loop()
{
    air_quality = (Firebase.getInt("Air_Quality"));
    altitude = (Firebase.getInt("Altitude"));
    cng = (Firebase.getInt("Cng"));
    humidity = (Firebase.getInt("Humidity"));
    ldr = (Firebase.getInt("Ldr"));
    lpg = (Firebase.getInt("Lpg"));
    pressure = (Firebase.getInt("Pressure"));
    rain_value = (Firebase.getInt("Rain_Value"));
    smoke = (Firebase.getInt("Smoke"));
    temperature = (Firebase.getInt("Temperature"));

    if (Firebase.failed()) {
        Serial.println(Firebase.error());
    }
    else
    {
        Serial.println();
        Serial.print("Air_Quality :- "); Serial.println(air_quality);
        Serial.print("Altitude :- "); Serial.println(altitude);
        Serial.print("Cng :- "); Serial.println(cng);        
        Serial.print("Humidity :- "); Serial.println(humidity);
        Serial.print("Ldr :- "); Serial.println(ldr);
        Serial.print("Lpg :- "); Serial.println(lpg);        
        Serial.print("Pressure :- "); Serial.println(pressure);
        Serial.print("Rain_Value :- "); Serial.println(rain_value);
        Serial.print("Smoke :- "); Serial.println(smoke);
        Serial.print("Temperature :- "); Serial.println(temperature);
        
}
 delay(1000);
}
