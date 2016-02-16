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
  int getValueAt(int i);
  Node* getNode(int index);
  std::string getsavedInput();

 private:
  Node* arrOfFreq[27];
  std::string savedInput;
};

#endif
