#ifndef MINHEAP_H
#define MINHEAP_H

#include "Node.h"
#include <vector>

using namespace std;
class minHeap{

 public:
  minHeap(std::string file);
  Node * getMin();
  void heapify(std::string file);
  void percolateUp();
  void percolateDown(int index);
  void insert(Node * toInsert);
  Node * connect(Node * min1, Node * min2); //returns the new parent node of the two mins- but only one node so I think it also doesn't need a *
  Node* run();
  void maintainInvariant();
  void swapNodes(int i,int j);
  void toString();
 private:
  std::vector<Node*> heap;
};

#endif
 
