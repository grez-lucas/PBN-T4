#include"graph.h"
#include<iostream>

int main(){
    Graph graph1(5);
    cout << graph1.nodeNum << endl;
    graph1.addEdge(0, 1);
    graph1.addEdge(0, 4);
    graph1.addEdge(1, 2);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 4);
    graph1.addEdge(2, 3);
    graph1.addEdge(3, 4);
 
    // print the adjacency list representation of the above graph
    graph1.printGraph();
    return 0;
}