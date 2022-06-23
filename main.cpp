#include"graph.h"
#include<iostream>

int main(){
    Graph g1;
    cout << g1.AdjacencyLists[0].node << endl;

    g1.add_nodo();
    g1.add_nodo();
    g1.add_nodo();
    g1.add_nodo();
    g1.add_nodo();
    g1.add_nodo();

    g1.add_arco(0, 1);
    g1.add_arco(1, 2);
    g1.add_arco(2, 3);
    g1.add_arco(3, 4);
 
    // print the adjacency list representation of the above graph
    g1.printGraph();
    cout << g1.hay_camino(4, 0) << endl;
    return 0;
}