#ifndef VECTOFNODE_H
#define VECTOFNODE_H

#include "Node.h"
#include <vector>

class vectOfNode{
 public:
  vectOfNode();
  ~vectOfNode();
  Node getParent();
  Node getlchild();
  Node getrchild();
  void setNode(char letter, int frequency);
 private:
  std::vector<Node> hoffSeg;
  int nextEmpty;  

};

#endif
