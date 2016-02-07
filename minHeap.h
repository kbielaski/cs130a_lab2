#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include "Node.h"

using namespace std;
class minHeap{

 public:
  minHeap();
  void deleteMin();
  void heapify(std::string file);
  void insert();
  void connect();

 private:
  Node* min1;
  Node* min2;
  std::vector<Node> heap;
};

#endif
