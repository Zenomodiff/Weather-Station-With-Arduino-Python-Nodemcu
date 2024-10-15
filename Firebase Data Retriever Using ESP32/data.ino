#include <WiFi.h>
#include <FirebaseESP32.h>

// Wi-Fi credentials
const char* ssid = "";            // Wi-Fi SSID
const char* password = "";           // Wi-Fi password

// Firebase project details
FirebaseConfig config;                       // Firebase configuration object
FirebaseAuth auth;                           // Firebase authentication object
FirebaseData firebaseData;                   // Firebase Data object

void setup() {
  Serial.begin(115200);                       // Start Serial Monitor

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("Connected to Wi-Fi\n");

  // Firebase configuration setup
  config.host = "data-check-4d938-default-rtdb.firebaseio.com/";
  config.signer.tokens.legacy_token = "AIzaSyA6urRGLm8sfOFRccm-wuWCef3ocQZ79CM";

  // Initialize Firebase
  Firebase.begin(&config, &auth);
}

void loop() {
  // Print a header for clarity
  Serial.println("=== Fetching Numbers from Firebase ===");

  // Fetch numbers from Firebase paths "/number/1" to "/number/5"
  for (int i = 1; i <= 5; i++) {
    String path = "/number/" + String(i);  // Create the path for each number
    if (Firebase.get(firebaseData, path)) {
      Serial.print("Number at ");
      Serial.print(path);
      Serial.print(": ");
      Serial.println(firebaseData.intData()); // Print the fetched number
    } else {
      Serial.print("Failed to get data from ");
      Serial.println(path);
    }
    delay(1000);  // Short delay to avoid overwhelming the server
  }

  // Print a footer for clarity
  Serial.println("=========================================\n");
  Serial.println();

  // Wait for 10 seconds before fetching again
  delay(10000);
}
