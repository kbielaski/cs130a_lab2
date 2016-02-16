#ifndef MINHEAP_H
#define MINHEAP_H

#include "Node.h"
#include <vector>
#include <map>

using namespace std;
class minHeap{

 public:
  minHeap(std::string file);
  Node * getMin();
  void heapify(std::string file);
  void insert(Node * toInsert);
  void percolateUp();
  void percolateDown(int index);
  void swapNodes(int i,int j);
  void toString();
  Node * connect(Node * min1, Node * min2); //returns the new parent node of the two mins- but only one node so I think it also doesn't need a *
  void encode(Node * n, std::string toAdd);
  bool layerabove(int index);
  void makeOne();
  Node* getHoff();

 private:
  std::vector<Node*> heap;
};

#endif
 
