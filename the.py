from flask import *
import json, time

app = Flask(__name__)


@app.route('/', methods=['GET'])
def home_page():
    data_set = {'page': 'home', 'Message': 'Sucessesfully loaded the homepage', 'timestamp': time.time()}
    json_dump = json.dumps(data_set)

    return json_dump
if __name__ == '__main__':
    app.run(port=5000)