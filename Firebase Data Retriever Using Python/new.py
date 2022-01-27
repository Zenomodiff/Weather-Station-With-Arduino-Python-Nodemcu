from weakref import ref
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from rsa import PrivateKey
import requests
import time
from random import *

cred = credentials.Certificate('firebase-sdk.json')

firebase_admin.initialize_app(cred, {

'databaseURL': 'https://weather-station-1514a-default-rtdb.firebaseio.com/'})

Air_Quality = db.reference("Air_Quality").get()
Altitude = db.reference("Altitude").get()
cng = db.reference("Cng").get()
Humidity = db.reference("Humidity").get()
Ldr = db.reference("Ldr").get()
Lpg =db.reference("Lpg").get()
Pressure =db.reference("Pressure").get()
Rain_Value =db.reference("Rain_Value").get()
Smoke = db.reference("Smoke").get()
Temperature = db.reference("Temperature").get()


print("Weather Station Data From Firebase With Time Stamp")
print("---------------------------------------------------")
print("Date & Time =" , time.asctime())
print("Air_Quality=" , Air_Quality)
print( "Altitude =",Altitude)
print("Cng =",cng)
print("Humidity =", Humidity)
print("Ldr =", Ldr)
print("Lpg =", Lpg)
print("Pressure =", Pressure)
print("Rain_Value =", Rain_Value)
print("Smoke =",Smoke)
print("Temperature =" ,Temperature)

with open("test.txt", "a") as file:
  file.write("\n")  
  file.write("Date & Time = ") 
  file.write(str(time.asctime()))  
  file.write("\n")  
  file.write("======================================") 
  file.write("\n") 
  file.write("Air_Quality = ")  
  file.write(str(Air_Quality))
  file.write("\n")
  file.write("Altitude = ") 
  file.write(str(Altitude))
  file.write("\n")
  file.write("Cng = ") 
  file.write(str(cng))
  file.write("\n")
  file.write("Humidity = ") 
  file.write(str(Humidity))
  file.write("\n")
  file.write("Ldr = ") 
  file.write(str(Ldr))
  file.write("\n")
  file.write("Lpg = ")
  file.write(str(Lpg))
  file.write("\n")
  file.write("Pressure = ")
  file.write(str(Pressure))
  file.write("\n")
  file.write("Rain_Value = ")
  file.write(str(Rain_Value))
  file.write("\n")
  file.write("Smoke = ")
  file.write(str(Smoke))
  file.write("\n")
  file.write("Temperature = ")
  file.write(str(Temperature))
  file.write("\n")