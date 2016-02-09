#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>

#include "Node.h"

using namespace std;
class minHeap{

 public:
  minHeap();
  minHeap(std::string file);
  Node * getMin();
  void heapify(std::string file);
  void maintainInvariant();
  void insert();
  Node * connect(Node * min1, Node * min2); //returns the new parent node of the two mins- but only one node so I think it also doesn't need a *
  Node* run();

 private:
  std::vector<Node*> heap;
};

#endif
 