from flask import Flask
from routes.web import web


app = Flask(__name__)
app.register_blueprint(web)

def start():
    app.run(host='0.0.0.0',
            port=5000,
            use_reloader=True,
            threaded=True)
