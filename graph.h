#pragma once
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
    int add_nodo();
    void add_arco(int, int);
    bool hay_arco(int, int);
    bool hay_camino(int, int);
    void printGraph();
};