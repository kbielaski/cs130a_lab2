#ifndef MINHEAP_H
#define MINHEAP_H

#include "Node.h"

using namespace std;
class minHeap{

 public:
  minHeap();
  minHeap(std::map toInsert);
  void deleteMin();
  void heapify();
  void insert();
  Node * connect(Node * min1, Node * min2); //returns the new parent node of the two mins
  void 

 private:
  Node* min1;
  Node* min2;
  Node** heap;         //three stars because it is a pointer to the root of a min heap which is implemented as an array and each element in the array is an array of smaller frequency nodes
};

#endif
