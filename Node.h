#ifndef NODE_H
#define NODE_H

class Node{
 public:
  Node();
  Node(int frequency);
  Node(char letter, int frequency);
  char getLetter();
  int getFrequency();
  void setFrequency(int frequency);
  void setLetter(int letter);
  
 private:
  char letter;          //if it is a connecting node then make the letter '!'
  int frequency;
  
  //freq* parent;       //I think we should implement this with an array also so that we don't need the pointers
  //freq* lchild;
  //freq* rchild;
};

#endif
