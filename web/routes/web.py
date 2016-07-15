from sys import argv
import requests
import json
import uuid
from flask import Flask, Blueprint, render_template, request, session, jsonify
import os

web = Blueprint('web', __name__)
app = Flask(__name__)


@web.route('/')
def index():
    return render_template('login.jinja2')
@web.route('/interface')
def interface():
    return render_template('interface.jinja2')