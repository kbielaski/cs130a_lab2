#ifndef MAKEMAPS_H
#define MAKEMAPS_H
#include "minHeap.h"
#include <map>
#include <string>

class makeMaps{
 public:
  makeMaps();
  void makeEncode(std::string file);
  //  std::string encode(Node* hoff, char letter);
  void makeDecode();

 private:
  std::map<char, int> encode;
  std::map<int, char> decode;

};
#endif
