#ifndef ARROFNODE_H
#define ARROFNODE_H

#include "Node.h"

class arrOfNode{
 public:
  arrOfNode();
  Node getParent();
  Node getlchild();
  Node getrchild();
 private:
  Node* hoffSeg;
  

};

#endif
