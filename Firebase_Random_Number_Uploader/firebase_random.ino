/*Before Building The Project You Can Simply Test 
The Firebase Database Functionality Using This Code*/


#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

float randNumber1;
float randNumber2;
float randNumber3;
float randNumber4;
float randNumber5;
float randNumber6;
float randNumber7;
float randNumber8;
float randNumber9;
float randNumber10;

#define FIREBASE_HOST "PASTE THE FIREBASEHOST ID"  
#define FIREBASE_AUTH "PASTE THE FIREBASE AUTH ID"  
#define WIFI_SSID "PASTE THE WIFI SSID"
#define WIFI_PASSWORD "PASTE THE WIFI PASSWORD"

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

Serial.println("Sending_Data");

randNumber1 = random(10);
randNumber2 = random(100000);
randNumber3 = random(10);
randNumber4 = random(100);
randNumber5 = random(100);
randNumber6 = random(10);
randNumber7 = random(1000);
randNumber8 = random(10);
randNumber9 = random(10);
randNumber10 = random(100);

  Firebase.setFloat ("Smoke",randNumber1);
  Firebase.setFloat ("Cng",randNumber2);
  Firebase.setFloat ("Lpg",randNumber3);
  Firebase.setFloat ("Air_Quality",randNumber4);
  Firebase.setFloat ("Rain_Value",randNumber5);
  Firebase.setFloat ("Temperature",randNumber6);
  Firebase.setFloat ("Humidity",randNumber7);
  Firebase.setFloat ("Ldr",randNumber8);
  Firebase.setFloat ("Pressure",randNumber9);
  Firebase.setFloat ("Altitude",randNumber10);
  delay(10000);

 if(Firebase.failed())
{
  Serial.println("Firebase log sending failed");
  Serial.println(Firebase.error());
  return;
}

}
