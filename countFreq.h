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
  Node** getArray();


 private:
  Node* arrOfFreq[29];
};

#endif
