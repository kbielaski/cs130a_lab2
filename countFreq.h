#ifndef COUNT_FREQ_H
#define COUNT_FREQ_H

#include "Node.h"
#include <map>
#include <string>

class countFreq{

 public:
  countFreq();
  void addLetters(std::string file);
  void printMap();
  int getValue(char c);


 private:
  std::map<char,int> table;
};

#endif
