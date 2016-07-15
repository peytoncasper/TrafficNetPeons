from flask import Flask
from flask import render_template, request
from flask_cors import CORS, cross_origin
import socket
app = Flask(__name__)

CORS(app)


@app.route('/')
def index():
    return render_template("index.html")

@app.route('/validate_login_camera_url')
def validate_login_camera_url():
    username = request.args.get('username')
    password = request.args.get('password')
    ip = socket.gethostbyname(socket.gethostname())

    return ip

@app.route('/step_right')
def step_right():

    username = request.args.get('username')
    password = request.args.get('password')

    pins = {22,23,24,25,26,27,28,29}
    # for pin in pins:
        # RPIO.setup(pin, RPIO.OUT)
        # RPIO.output(pin, False)
    sequence = {{1, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 1},
                {0, 0, 0, 1},
                {1, 0, 0, 1}};

    for i in range(0, 50):
        for halfstep in range(0, 8):
            for pin in range(0, 4):
                # RPIO.output(pins[pin], sequence[halfstep][pin])
                print "Cycle"
            # delay(1)

    for pin in pins:
        # RPIO.output(pins[pin], 0)
        print "Setting pin low"



    return ""
def step_left():
    return ""
def step_forward():
    return ""
def step_backwards():
    return ""



if __name__ == '__main__':
    app.run()
