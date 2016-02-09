#ifndef NODE_H
#define NODE_H

#include <string>

class Node{
 public:
  Node();
  Node(int frequency);
  Node(char letter, int frequency);
  char getLetter();
  int getFrequency();
  void setFrequency(int frequency);
  void setLetter(char letter);
  Node * getLchild();
  Node * getRchild();
  Node * getParent();
  void setLchild(Node * lchild);
  void setRchild(Node * rchild);
  void setParent(Node * parent);
  void setCode(std::string code);
  std::string getCode();
  
 private:
  char letter;          //if it is a connecting node then make the letter '!'
  int frequency;
  std::string code;
  
  Node* parent;       //I think we should implement this with an array also so that we don't need the pointers
  Node* lchild;
  Node* rchild;
};

#endif
