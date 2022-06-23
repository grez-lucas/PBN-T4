import grafo as g

g1 = g.Graph(6)

g1.add_arco(0, 1)
g1.add_arco(1, 2)
g1.add_arco(3, 4)

g1.printGraph()
print (f'Entre los nodos 0 y 4 hay camino: {g1.hay_camino(0,4)}' )