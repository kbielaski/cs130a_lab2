#ifndef NODE_H
#define NODE_H

class Node{
 public:
  void getParent();
  void getlchild();
  void getrchild();
  char getLetter();
  int getFrequency();
  void setFrequency();

 private:
  char letter;          //if it is a connecting node then make the letter '!'
  int f;
  freq* parent;
  freq* lchild;
  freq* rchild;
};

#endif
