#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>

#include "Node.h"

using namespace std;
class minHeap{

 public:
  minHeap();
  minHeap(std::map toInsert);
  Node getMin();
  void deleteMin();
  void heapify(std::string file);
  void insert();
  Node connect(Node * min1, Node * min2); //returns the new parent node of the two mins- but only one node so I think it also doesn't need a *
  Node* run();

 private:
  Node* min1;        //are there supposed to be stars here because it is only pointing to one node????
  Node* min2;
  std::vector<Node> heap;
};

#endif
