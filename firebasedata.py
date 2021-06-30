import pyrebase

config = {    
    "apiKey": "FIREBASE API KEY",
    "authDomain": "FIREBASE DOMAIN",
    "databaseURL": "FIREBASE DATABSE URL",
    "projectId": "FIREBASE PROJECT ID",
    "storageBucket": "FIREBASE PROJECT BUCKET",
    "messagingSenderId": "FIREBASE SENDER ID",
    "appId": "FIREBASE APP ID",
    "measurementId": "FIREBASE MEASUREMENT ID"
}

firebase = pyrebase.initialize_app(config)
database = firebase.database()

weatherdata = database.child("Air_Quality").get()
Altitude = database.child("Altitude").get()
cng = database.child("Cng").get()
Humidity = database.child("Humidity").get()
Ldr = database.child("Ldr").get()
Lpg =database.child("Lpg").get()
Pressure =database.child("Pressure").get()
Rain_Value =database.child("Rain_Value").get()
Smoke = database.child("Smoke").get()
Temperature = database.child("Temperature").get()



print("Weather Station Data From Firebase")
print()
print("Air_Quality=" , weatherdata.val())
print( "Altitude =",Altitude.val())
print("Cng =",cng.val())
print("Humidity =", Humidity.val())
print("Ldr =", Ldr.val())
print("Lpg =", Lpg.val())
print("Pressure =", Pressure.val())
print("Rain_Value =", Rain_Value.val())
print("Smoke =",Smoke.val())
print("Temperature =" ,Temperature.val())
