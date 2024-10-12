#include <WiFi.h>
#include <Firebase_ESP_Client.h>

float randnumber1;
float randnumber2;
float randnumber3;
float randnumber4;
float randnumber5;

#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "Enter_SSID"
#define WIFI_PASSWORD "Enter_PASSWORD"
#define API_KEY "Enter_API_KEY"
#define DATABASE_URL "Enter_DATABASE_URL" 
#define USER_EMAIL "Enter_EMAIL_ID"
#define USER_PASSWORD "Enter_EMAIL_PASSWORD"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

void setup()
{

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; 
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
}

void loop()
{
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 10000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();

    randnumber1 = random(100);
    randnumber2 = random(100);
    randnumber3 = random(100);
    randnumber4 = random(100);
    randnumber5 = random(100);


    Serial.printf("Number: %s\n", Firebase.RTDB.setFloat(&fbdo, F("/number/1"), randnumber1) ? "ok" : fbdo.errorReason().c_str());
    Serial.printf("Number: %s\n", Firebase.RTDB.setFloat(&fbdo, F("/number/2"), randnumber2) ? "ok" : fbdo.errorReason().c_str());
    Serial.printf("Number: %s\n", Firebase.RTDB.setFloat(&fbdo, F("/number/3"), randnumber3) ? "ok" : fbdo.errorReason().c_str());
    Serial.printf("Number: %s\n", Firebase.RTDB.setFloat(&fbdo, F("/number/4"), randnumber4) ? "ok" : fbdo.errorReason().c_str());
    Serial.printf("Number: %s\n", Firebase.RTDB.setFloat(&fbdo, F("/number/5"), randnumber5) ? "ok" : fbdo.errorReason().c_str());
  }
}
