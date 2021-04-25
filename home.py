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

@app.route('/ListaDobleEnlazada')
def listade():
    return render_template('code/listade.html')

@app.route('/ListaCircularSimple')
def listaC():
    return render_template('code/circularS.html')

@app.route('/ListaDobleCircularEnlazada')
def listaCD():
    return render_template('code/circularD.html')

@app.route('/ArbolAVL')
def arbolAVL():
    return render_template('code/arbolAVL.html')

@app.route('/Pilas')
def pila():
    return render_template('code/pilaA.html')

@app.route('/Colas')
def cola():
    return render_template('code/colas.html')


@app.route('/ArbolBinario')
def binario():
    return render_template('code/arbolbi.html')




if __name__ == '__main__':
    app.run(debug=True)