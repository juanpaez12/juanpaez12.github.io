from flask import Flask, render_template

app = Flask(__name__)

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

@app.route('/ArbolAVL')
def arbolAVL():
    return render_template('code/arbolAVL.html')

@app.route('/Pilas')
def pila():
    return render_template('code/pilaA.html')
@app.route('/PilaE')
def PilaE():
    return render_template('estructuras/Pilas.html')

@app.route('/PilaP')
def PilaP():
    return render_template('pythoncode/pila.html')

@app.route('/Colas')
def cola():
    return render_template('code/colas.html')

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

@app.route('/ArbolBinarioP')
def ArbolBinarioP():
    return render_template('pythoncode/arbolbi.html')

@app.route('/Simple')
def simple():
    return render_template('estructuras/Listasimple.html')


if __name__ == '__main__':
    app.run(debug=True)