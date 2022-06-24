#include"graph.h"
#include<iostream>

int main(){
    Graph g1 = Graph(3);
    cout << g1.AdjacencyLists[0].node << endl;


    g1.add_arco(1, 2);
    g1.add_nodo();
     // g1.add_arco(2, 3);
 
    // print the adjacency list representation of the above graph
    g1.printGraph();
    // cout << g1.hay_arco(2, 1) << endl;
    // cout << g1.hay_camino(1, 3) << endl;
    return 0;
}