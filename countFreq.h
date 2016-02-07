#ifndef COUNT_FREQ_H
#define COUNT_FREQ_H

#include "Node.h"
#include <map>
#include <string>

class countFreq{

 public:
  countFreq();
  ~countFreq();
  void addLetters(std::string file);
  void printMap();
  int getValue(char c);
  std::vector<Node> getVectOfNode();


 private:
  std::map<char,int> table;
  std::vector<Node> heap;
};

#endif
