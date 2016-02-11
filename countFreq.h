#ifndef COUNT_FREQ_H
#define COUNT_FREQ_H

#include "Node.h"
#include <map>
#include <string>

class countFreq{

 public:
  countFreq();
  void addLetters(std::string file);
  void print();
  int getValue(char c);
  Node* getNode(int index);


 private:
  Node* arrOfFreq[28];
};

#endif
