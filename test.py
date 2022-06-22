import grafo as g

g1 = g.Graph(5)

g1.addEdge(1, 3)
g1.addEdge(1, 4)
g1.addEdge(2, 3)
g1.addEdge(3, 4)

g1.printGraph()