#include<list>
#include<vector>
#include "adj_list.h"
//It is faster to use adjacency lists for graphs having less number of edges.
using namespace std;


class Graph{
public:
    int nodeNum;
    AdjacencyList * AdjacencyLists;
    Graph();
    Graph(int);
    Node* newAdjListNode(int);
    void addEdge(int, int);
    void printGraph();
};