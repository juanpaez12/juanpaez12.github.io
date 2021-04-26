from flask import Flask, render_template, request, flash, redirect, url_for, send_file

import os

from werkzeug.utils import secure_filename

app = Flask(__name__)

app.config['UPLOAD_FOLDER'] = 'templates/ArchivosPython'

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/home')
def index():
    return render_template('index.html')

@app.route('/ListaEnlazada')
def listase():
    return render_template('code/listase.html')

@app.route('/ListaEP')
def listasep():
    return render_template('pythoncode/listase.html')

@app.route('/ListaEC')
def listaEC():
    return render_template('C++/Listasimplec.html')

@app.route('/ListaDobleEnlazada')
def listade():
    return render_template('code/listade.html')

@app.route('/ListaD')
def listad():
    return render_template('/estructuras/ListasDoble.html')

@app.route('/ListaDp')
def listadp():
    return render_template('/pythoncode/listade.html')

@app.route('/ListaEDC')
def listaEDC():
    return render_template('C++/Listasdoblec.html')

@app.route('/ListaCircularSimple')
def listaC():
    return render_template('code/circularS.html')

@app.route('/ListaCS')
def listaCS():
    return render_template('/estructuras/ListaCircularS.html')

@app.route('/ListaCSP')
def listaCSP():
    return render_template('pythoncode/circularS.html')

@app.route('/ListaCSC')
def listaCSC():
    return render_template('C++/circularsimple.html')

@app.route('/ListaDobleCircularEnlazada')
def listaCDo():
    return render_template('code/circularD.html')

@app.route('/ListaCD')
def listaCD():
    return render_template('/estructuras/ListaCircularD.html')

@app.route('/ListaCDP')
def listaCDP():
    return render_template('pythoncode/circularD.html')

@app.route('/ListaCDC')
def listaCDC():
    return render_template('C++/doblecircular.html')


@app.route('/Pilas')
def pila():
    return render_template('code/pilaA.html')

@app.route('/PilasC')
def pilaC():
    return render_template('C++/pilac.html')

@app.route('/PilaE')
def PilaE():
    return render_template('estructuras/Pilas.html')

@app.route('/PilaP')
def PilaP():
    return render_template('pythoncode/pila.html')

@app.route('/Colas')
def cola():
    return render_template('code/colas.html')

@app.route('/ColasC')
def colaC():
    return render_template('C++/colaC.html')

@app.route('/Colase')
def colae():
    return render_template('estructuras/colas.html')

@app.route('/Colasp')
def colap():
    return render_template('pythoncode/colas.html')


@app.route('/ArbolBinarioE')
def binarioE():
    return render_template('estructuras/Arbolbi.html')

@app.route('/ArbolBinarioC')
def binarioc():
    return render_template('code/arbolbi.html')



@app.route('/Simple')
def simple():
    return render_template('estructuras/Listasimple.html')

@app.route('/Grafo', methods=['GET', 'POST'])
def informacion():
    error = None
    if request.method == "POST":
        f = request.files["archivo"]
        if f.filename == "":
            
            return redirect(url_for('modulo3'))
        
        filename = secure_filename(f.filename)
        path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        f.save(path)

    url = "python templates/Transformaciones.py " + filename
    os.system(url)
    os.remove(path)
    return render_template('grafo.html')

@app.route('/grafo', methods=['GET', 'POST'])
def xmlGrafo():
    error = None
    if request.method == "POST":
        f = request.files["xml"]
        if f.filename == "":
            
            return redirect(url_for('modulo3'))
        
        filename = secure_filename(f.filename)
        path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        f.save(path)

    url = "python templates/XML.py " + filename
    os.system(url)
    os.remove(path)
    return render_template('graphml.html')
    
@app.route('/Download')
def Download():
    return send_file('static/downl')


@app.route('/Transformaciones')
def modulo3():
    
    return render_template('analizador.html')



if __name__ == '__main__':
    app.run(debug=True)