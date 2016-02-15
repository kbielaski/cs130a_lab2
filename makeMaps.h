#ifndef MAKEMAPS_H
#define MAKEMAPS_H
#include "minHeap.h"
#include <map>

class makeMaps{
 public:
  makeMaps();
  void makeEncode(Node* hoff);
  void makeDecode(Node* hoff);

 private:
  std::map<char, int> encode;
  std::map<int, char> decode;

};
#endif
