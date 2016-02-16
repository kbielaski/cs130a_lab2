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
  void encodeHelper(Node * root);
  std::string makeEncodedString(std::string input);
  std::string makeDecodedString(std::string input);
 private:
  std::map<char, std::string> encode;
  std::map<std::string, char> decode;

};
#endif
