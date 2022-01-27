from weakref import ref
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

cred = credentials.Certificate('firebase-sdk.json')

firebase_admin.initialize_app(cred, {

'databaseURL': 'https://weather-station-1514a-default-rtdb.firebaseio.com/'})

weatherdata = db.reference("Air_Quality").get()
Altitude = db.reference("Altitude").get()
cng = db.reference("Cng").get()
Humidity = db.reference("Humidity").get()
Ldr = db.reference("Ldr").get()
Lpg =db.reference("Lpg").get()
Pressure =db.reference("Pressure").get()
Rain_Value =db.reference("Rain_Value").get()
Smoke = db.reference("Smoke").get()
Temperature = db.reference("Temperature").get()

print("Weather Station Data From Firebase")
print("------------------------------------")
print("Air_Quality=" , weatherdata)
print( "Altitude =",Altitude)
print("Cng =",cng)
print("Humidity =", Humidity)
print("Ldr =", Ldr)
print("Lpg =", Lpg)
print("Pressure =", Pressure)
print("Rain_Value =", Rain_Value)
print("Smoke =",Smoke)
print("Temperature =" ,Temperature)