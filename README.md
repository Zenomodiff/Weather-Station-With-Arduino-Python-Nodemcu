# Weather-Station-With-Arduino-Nodemcu
This Weather Station Uses Arduino , Nodemcu Along With Different Analog  Value Sensor & Digital Value Sensors. 
Since Nodemcu Have Only One A0 Pin & We Need Values From Different Analog Sensors Like :--

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

I Use This [Arduinojson 6.13.0](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-6.13.0.zip) Library For [SERIAL MONITOR DATA](https://user-images.githubusercontent.com/25906435/118393393-86381180-b65c-11eb-9b50-215d0a341aa8.png) -- [BLYNK](https://blynk.io/) -- [THINGSPEAK](https://thingspeak.com/) -- [IFTTT](https://ifttt.com/) & [UBIDOTS](https://ubidots.com/)

Then I Use This [Arduinojson 5.13.1](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-5.13.1.zip) Library For [FIREBASE](https://firebase.google.com) , [ADAFRUIT-IO](https://io.adafruit.com/)  Other Arduinojson Library Does Not Work Beacuse I Use DynamicJsonDocument doc(1024); For Converting Data From Arduino To Nodemcu It Is An [Arduinojson 6.13.0](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-6.13.0.zip) Variant & Not Yet Compactable With FirebaseArduino.h & Adafruit_MQTT.h Library , So I Have Downgraded To This [Arduinojson 5.13.1](https://downloads.arduino.cc/libraries/github.com/bblanchon/ArduinoJson-5.13.1.zip) Library . I Need To Do Some Tweeks In The Code To Make It All Work & All The Arduino Files Have Been Updated In The Repository

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

![Screenshot (258)](https://user-images.githubusercontent.com/25906435/118621314-df7e7d00-b7e3-11eb-8ba2-2c568cd2aa0e.png)

DATA RECIEVED BY [ADAFRUIT-IO](https://io.adafruit.com/) WEBSITE

(in the adafruit io website i have only shown 8 diff values beacuse the adafruit dont let me add more since the field was full )

![Screenshot (359)](https://user-images.githubusercontent.com/25906435/119191020-c0117980-ba9b-11eb-8f94-e5fa19a67de7.png)

DATA RECIEVED IN EMAIL BY [IFTTT](https://ifttt.com/)

(in the iftt website iam only able to create 3 values for the weatherstation since in the ifttt applet we can only craete 3 value action even_though it is useful)

![Screenshot (462)](https://user-images.githubusercontent.com/25906435/119258444-3f5f9400-bbe7-11eb-87d3-d196368f5a3b.png)

DATA RECIEVED BY [UBIDOTS](https://ubidots.com/)

![Screenshot (507)](https://user-images.githubusercontent.com/25906435/119342676-0ab90e80-bcb3-11eb-85ea-585a2b6ba49a.png)

