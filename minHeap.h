#ifndef MINHEAP_H
#define MINHEAP_H

#include "arrOfNode.h"

class minHeap{

 public:
  minHeap();
  void deleteMin();
  void heapify();
  void insert();
  void connect();

 private:
  Node* min1;
  Node* min2;
  Node*** heap;         //three stars because it is a pointer to the root of a min heap which is implemented as an array and each element in the array is an array of smaller frequency nodes
};

#endif
