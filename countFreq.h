#ifndef COUNT_FREQ_H
#define COUNT_FREQ_H

#include "Node.h"
#include <map>
#include <string>
#include <vector>

class countFreq{

 public:
  countFreq();
  void addLetters(std::string file);
  void print();
  int getValue(int c);
  Node* getNode(int index);


 private:
  Node* arrOfFreq[28];
};

#endif
