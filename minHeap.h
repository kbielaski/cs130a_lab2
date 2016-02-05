#ifndef MINHEAP_H
#define MINHEAP_H

#include "Node.h"

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

  Node** heap;
};

#endif
