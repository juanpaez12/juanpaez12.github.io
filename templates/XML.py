import networkx as nx
import matplotlib.pyplot as plt
import sys


ruta = sys.argv
url = "templates/ArchivosPython/" + ruta[1]

grafo = nx.read_graphml(url)
pos = nx.spring_layout(grafo)


color_node = []
for nodo in grafo.nodes():
    if grafo.nodes[nodo]['tipo'] == 'class':
        color_node.append('red')
    elif grafo.nodes[nodo]['tipo'] == 'metodo':
        color_node.append('yellow')
    elif grafo.nodes[nodo]['tipo'] == 'atributo':
        color_node.append('#00AAE4')

nx.draw(grafo, pos, node_size=600, node_color=color_node, font_size=8, font_weight='bold',with_labels=True, font_family='Lato')


plt.tight_layout()

plt.savefig("static/GraphXML.png", format="PNG", dpi= 500)
