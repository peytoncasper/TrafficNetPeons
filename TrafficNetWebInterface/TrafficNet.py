from flask import Flask
from flask import render_template, request
from flask_cors import CORS, cross_origin
from gpiozero import LED
import time
import socket, json
app = Flask(__name__)

CORS(app)


@app.route('/')
def index():
    return render_template("index.html")

@app.route('/validate_login_camera_url')
def validate_login_camera_url():
    username = request.args.get('username')
    password = request.args.get('password')

    with open('config.json') as data_file:
        data = json.load(data_file)
        if username == data["username"] and password == data["password"]:
            return json.dumps({
                "ipAddress":socket.gethostbyname(socket.gethostname()),
                "title": data["title"],
                "description": data["description"],
                "direction": ""
            })
        else:
            return ""

@app.route('/get_title_description')
def get_title_description():
    username = request.args.get('username')
    password = request.args.get('password')

    with open('config.json') as data_file:
        data = json.load(data_file)
        if username == data["username"] and password == data["password"]:
            return json.dumps({
                "title": data["title"],
                "description": data["description"],
            })
        else:
            return ""

@app.route('/save_settings')
def save_settings():
    username = request.args.get('username')
    password = request.args.get('password')
    title = request.args.get('title')
    description = request.args.get('description')

    authenticated = False

    with open('config.json') as data_file:
        data = json.load(data_file)
        if username == data["username"] and password == data["password"]:
            authenticated = True

    if authenticated:
        with open('config.json', 'w') as data_file:

            data["title"] = title
            data["description"] = description
            data_file.write(json.dumps(data))

            return json.dumps({
                "title": data["title"],
                "description": data["description"],
            })
    else:
        return ""

@app.route('/step_right')
def step_right():

    username = request.args.get('username')
    password = request.args.get('password')
    
    with open('config.json') as data_file:
        data = json.load(data_file)
        if username == data["username"] and password == data["password"]:
            pins = [LED(12), LED(16), LED(20), LED(21)]
            for pin in pins:
                pin.off()
            sequence = [[1, 0, 0, 0],
                        [1, 1, 0, 0],
                        [0, 1, 0, 0],
                        [0, 1, 1, 0],
                        [0, 0, 1, 0],
                        [0, 0, 1, 1],
                        [0, 0, 0, 1],
                        [1, 0, 0, 1]];

            for i in range(0, 32):
                for halfstep in range(0, 8):
                    for pin in range(0, len(pins)):
                        if sequence[halfstep][pin] == 1:
                            pins[pin].on()
                        else:
                            pins[pin].off()
                        
                        
                    time.sleep(.001)

            for pin in pins:
                pin.off()
                print "Setting pin low"
        else:
            return ""

def step_left():
    return ""
def step_forward():
    return ""
def step_backwards():
    return ""



if __name__ == '__main__':
    app.run(host='0.0.0.0')
