# Weather-Station-With-Arduino-Nodemcu-
This Weather Station Uses Arduino And Nodemcu , Since Nodemcu Have Only One A0 Pin & We Need Values From Different Analog Sensors Like :--

Sensor         | Data
----           | ------
MQ2            | SMOKE 
MQ4            | CNG 
MQ5            | LPG
MQ135          | AIR QUALITY
LDR            | LIGHT INTENSITY
RAIN SENSOR    | RAIN INTENSITY
DHT22          | TEMPERATURE & HUMIDITY  
BMP280         | PRESSURE & ALTITUDE 


So I Use ArduinoJson Library To Sent Values Collected From Sensors Via Arduino As "DOC" & Print It In Nodemcu Serial Monitor , Thats One-Way To Show Multiple Analog Readings In Nodemcu Board .

I Use This [Arduinojson 6.13.0](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-6.13.0.zip) Library For SERIAL MONITOR DATA, [BLYNK](https://blynk.io/) , [THINGSPEAK](https://thingspeak.com/) 

Then I Use This [Arduinojson 5.13.1](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-5.13.1.zip) Library For Firebase Realtime Data Streaming , Other Arduinojson Library Does Not Work Beacuse I Use DynamicJsonDocument doc(1024); For Converting Data From Arduino To Nodemcu It Is A [Arduinojson 6.13.0](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-6.13.0.zip) Variant & Not Yet Compactable With FirebaseArduino.h Library So I Have Downgraded To This [Arduinojson 5.13.1](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-5.13.1.zip) Library .I Do Need To Do Some Tweeks In The Code To Make It Work & All The Arduino Files Have Been Updated .

List Of Other Arduinojson [Libraries](https://www.arduinolibraries.info/libraries/arduino-json)

DEVICE VIEW

![IMG_20210508_001355](https://user-images.githubusercontent.com/25906435/118393866-ec259880-b65e-11eb-849f-6b332e847f9f.jpg)

SOLDERING JOB 

![IMG_20210508_021712](https://user-images.githubusercontent.com/25906435/118393871-f8a9f100-b65e-11eb-8395-6a28c39265ce.jpg)


DATA SENT BY ARDUINO AS JSON "DOC"

![Screenshot (235)](https://user-images.githubusercontent.com/25906435/118393371-71f41480-b65c-11eb-94cd-511564734ba4.png)

DATA RECIEVED BY NODEMCU IN SERIAL MONITOR

![Screenshot (238)](https://user-images.githubusercontent.com/25906435/118393393-86381180-b65c-11eb-9b50-215d0a341aa8.png)

DATA RECIEVED BY [BLYNK](https://blynk.io/) APP

(in the blynk app i have only shown 6 diff values beacuse the blynk energy was not enough to place new guage fields for others )

![Screenshot_2021-05-09-02-48-05-557_cc blynk](https://user-images.githubusercontent.com/25906435/118393486-12e2cf80-b65d-11eb-97fb-504bba5522a6.jpg)

DATA RECIEVED BY [THINGSPEAK](https://thingspeak.com/) WEBSITE

![Screenshot_2021-05-16-20-10-31-062_com android chrome](https://user-images.githubusercontent.com/25906435/118401476-85ff3c80-b683-11eb-8f7d-4bb1ef685694.jpg)

DATA RECIEVED BY [FIREBASE](https://firebase.google.com) WEBSITE

![Screenshot (255)](https://user-images.githubusercontent.com/25906435/118559890-479e7600-b786-11eb-946b-ab6995009c94.png)



