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

So We Use Json Library To Sent Values Collected From Sensors Via Arduino As "DOC" & Print It In Serial Monitor Of Nodemcu , Thats One-Way To Show Multiple Analog Readings In Nodemcu Board .

DEVICE VIEW

![IMG_20210508_001355](https://user-images.githubusercontent.com/25906435/118393866-ec259880-b65e-11eb-849f-6b332e847f9f.jpg)

SOLDERING JOB 

![IMG_20210508_021712](https://user-images.githubusercontent.com/25906435/118393871-f8a9f100-b65e-11eb-8395-6a28c39265ce.jpg)


DATA SENT BY ARDUINO AS JSON "DOC"

![Screenshot (235)](https://user-images.githubusercontent.com/25906435/118393371-71f41480-b65c-11eb-94cd-511564734ba4.png)

DATA RECIEVED BY NODEMCU IN SERIAL MONITOR

![Screenshot (238)](https://user-images.githubusercontent.com/25906435/118393393-86381180-b65c-11eb-9b50-215d0a341aa8.png)

DATA RECIEVED BY BLYNK APP

(in the blynk app i have only shown 6 diff values beacuse the blynk energy was not enough to place new guage fields for thers )

![Screenshot_2021-05-09-02-48-05-557_cc blynk](https://user-images.githubusercontent.com/25906435/118393486-12e2cf80-b65d-11eb-97fb-504bba5522a6.jpg)

