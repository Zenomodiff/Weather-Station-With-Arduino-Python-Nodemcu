# Weather-Station-With-Arduino-Nodemcu-
This Weather Station Uses Arduino And Nodemcu , Since Nodemcu Have Only One A0 Pin & We Need Values From Different Analog Sensors Like :--

MQ2 --> Smoke 

MQ4 --> Cng

MQ5 --> Lpg

MQ135 --> Air Quality

LDR --> Light Intensity

Rain Sensor --> Rain Value

DHT 22  --> Temperature & Humidity

BMP280  --> Pressure & Altitude

We Use Json Library To Sent Values From Sensor's As "DOC" & Print It In Serial Monitor Of Nodemcu ,So The Job Is Easy 

DATA SENT BY ARDUINO AS JSON "DOC"

![Screenshot (235)](https://user-images.githubusercontent.com/25906435/118393371-71f41480-b65c-11eb-94cd-511564734ba4.png)

DATA RECIEVED BY NODEMCU IN SERIAL MONITOR

![Screenshot (238)](https://user-images.githubusercontent.com/25906435/118393393-86381180-b65c-11eb-9b50-215d0a341aa8.png)

DATA RECIEVED BY BLYNK APP (in the blynk app i have only shown 6 diff values beacuse the blynk energy was not enough to place new fields for thers )

![Screenshot_2021-05-09-02-48-05-557_cc blynk](https://user-images.githubusercontent.com/25906435/118393486-12e2cf80-b65d-11eb-97fb-504bba5522a6.jpg)

