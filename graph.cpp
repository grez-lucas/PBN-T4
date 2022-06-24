#include "graph.h"
#include <iostream>
#include<list>

Graph::Graph()
{
  this->nodeNum = 0;
  AdjacencyLists = new AdjacencyList[0];
  AdjacencyLists[0].node = NULL;
}

Graph::Graph(int size)
{
  this->nodeNum = size;
  AdjacencyLists = new AdjacencyList[size*2];
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

void Graph::add_arco(int src, int dest)
{
  Node *newNode = newAdjListNode(dest);
  newNode->next = AdjacencyLists[src].node;
  AdjacencyLists[src].node = newNode;
  newNode = newAdjListNode(src);
  newNode->next = AdjacencyLists[dest].node;
  AdjacencyLists[dest].node = newNode;
}

bool Graph::hay_arco(int a, int b){
    Node *aNode = AdjacencyLists[a].node;
    while(aNode){
      if(aNode->dest == b) return true;
      aNode = aNode->next;
    }
    return false;
}

bool Graph::hay_camino(int a, int b)
{
  //BFS Algorithm
  if (a == b) 
    return true;

  //Mark all nodes as unvisited
  bool *visited = new bool[this->nodeNum];
  for(int i = 0; i < this->nodeNum; ++i)
    visited[i] = false;
  
  list<int> queue;

  // Mark first node as visited
  visited[a] = true;
  // Add to queue all adjacent nodes of the first node
  Node *currentNode = AdjacencyLists[a].node;
  while(currentNode){
    queue.push_back(currentNode->dest);
    currentNode = currentNode->next;
  }

  //Begin to loop over queue, checking if the node has been visited or not
  while(!queue.empty()){
    currentNode = AdjacencyLists[queue.front()].node;
    visited[queue.front()] = true;
    //Put adjacent nodes in queue if they're not visited
    while(currentNode){
      if(!visited[currentNode->dest])
        queue.push_back(currentNode->dest);
      currentNode = currentNode->next;
    }
    //Remove the first element of the queue
    queue.pop_front();
  }
  return visited[b];
  }

void Graph::printGraph()
{
  for (int v = 0; v < this->nodeNum; ++v)
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