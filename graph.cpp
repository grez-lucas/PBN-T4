#include "graph.h"
#include <iostream>

Graph::Graph()
{
  this->nodeNum = 0;
  AdjacencyLists = new AdjacencyList[0];
  AdjacencyLists[0].node = NULL;
}

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

int Graph::add_nodo(){  //Gotta play with realloc memory 
  this->nodeNum ++;
  int id = this->nodeNum;
  
  Node *newNode = new Node;
  newNode->next = NULL;

  AdjacencyLists[id].node = NULL;


  return id;
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
    Node *printNode = AdjacencyLists[v].node;
    cout << "Adjacency list of node " << v << "\n node ";
    // Print each node's destination, until there's no more nodes left in ajdList to iterate
    while (printNode)
    {
      cout << "-> " << printNode->dest;
      printNode = printNode->next;
    }
    cout << endl;
  }
}