# -*- coding: utf-8 -*-



import networkx as nx
import matplotlib.pyplot as plt
import sys
from networkx.readwrite import json_graph

ruta = sys.argv
url = "templates/ArchivosPython/" + ruta[1]
archivo = open(url,"r")



G = nx.Graph()

node_text = []

numClase = 0
numAtri = 0
numMet = 0



nombreClase = ""
for linea in archivo.readlines():
    esClase = linea.find("class")
    esMetodo = linea.find("def")
    
    
    
    if esClase != -1 :
        if linea[esClase+5] == " ":
            clase = linea.split()
            nombreClase = clase[1][:-1]
            numClase -= 1
            G.add_node(nombreClase, tipo='class')
            
            
            node_text.append(nombreClase)
    
    if esMetodo != -1 :
        metodo = linea.split()
        metodo.remove("def")
        nombreMetodo = ""
        for m in metodo:
            nombreMetodo += m
           
        nombreMetodo = nombreMetodo[:-1]
        nombreMetodo = nombreMetodo.split("(")
        nombreMetodo[1] = nombreMetodo[1][:-1]
        atributos = nombreMetodo[1].split(",")
        
         
        
        numMet += 1
        G.add_node(nombreMetodo[0], tipo='metodo')
        G.add_edge(nombreClase, nombreMetodo[0])
        node_text.append(nombreMetodo[0])
        
        
        for atr in atributos:
            if atr is not node_text :
                numAtri += 2
                G.add_node(atr, tipo='atributo')
                node_text.append(atr)
            G.add_edge(atr, nombreMetodo[0])
                
        


color_node = []
for nodo in G.nodes():
    if G.nodes[nodo]['tipo'] == 'class':
        color_node.append('red')
    elif G.nodes[nodo]['tipo'] == 'metodo':
        color_node.append('yellow')
    elif G.nodes[nodo]['tipo'] == 'atributo':
        color_node.append('#00AAE4')




pos = nx.spring_layout(G)
nx.draw(G, pos, node_size=600, node_color=color_node, font_size=8, font_weight='bold',with_labels=True, font_family='Lato')

plt.tight_layout()

plt.savefig("static/Graph.png", format="PNG", dpi= 300)











