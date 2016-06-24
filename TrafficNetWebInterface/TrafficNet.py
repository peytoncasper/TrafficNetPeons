from flask import Flask
from flask import render_template

app = Flask(__name__)


@app.route('/')
def index():
    return render_template("index.html")

def step_right():
    return ""
def step_left():
    return ""
def step_forward():
    return ""
def step_backwards():
    return ""

if __name__ == '__main__':
    app.run()
