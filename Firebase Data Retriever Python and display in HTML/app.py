from flask import Flask, render_template
import firebase_admin
from firebase_admin import credentials, db

app = Flask(__name__)

# Initialize Firebase Admin SDK with your service account credentials
cred = credentials.Certificate(r"C:\Users\sreer\OneDrive\Desktop\New folder\firebase_config\data-check-4d938-firebase-adminsdk-xgbml-21dd80a38c.json")
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://data-check-4d938-default-rtdb.firebaseio.com/'  # Replace with your Firebase database URL
})

@app.route('/')
def index():
    # Reference to the 'number' array in the Firebase database
    ref = db.reference('number')
    data = ref.get()

    # Remove the 'null' entry and process the rest
    if data:
        numbers = [num for num in data if num is not None]  # Filter out null
    else:
        numbers = []

    return render_template('index.html', numbers=numbers)  # Pass the numbers to the template

if __name__ == '__main__':
    app.run(debug=True)
