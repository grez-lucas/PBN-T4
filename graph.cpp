#include "graph.h"
#include <iostream>

Graph::Graph(int size)
{
  this->nodeNum = size;
  AdjacencyLists = new AdjacencyList[size];
  for (int i = 0; i < size; ++i)
    AdjacencyLists[i].node = NULL;
}
Node *Graph::newAdjListNode(int dest)
{
  Node *newNode = new Node;
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

void Graph::addEdge(int src, int dest)
{
  Node *newNode = newAdjListNode(dest);
  newNode->next = AdjacencyLists[src].node;
  AdjacencyLists[src].node = newNode;
  newNode = newAdjListNode(src);
  newNode->next = AdjacencyLists[dest].node;
  AdjacencyLists[dest].node = newNode;
}
void Graph::printGraph()
{
  int v;
  for (v = 0; v < this->nodeNum; ++v)
  {
    Node *pCrawl = AdjacencyLists[v].node;
    cout << "\n Adjacency list of node " << v << "\n head ";
    while (pCrawl)
    {
      cout << "-> " << pCrawl->dest;
      pCrawl = pCrawl->next;
    }
    cout << endl;
  }
}