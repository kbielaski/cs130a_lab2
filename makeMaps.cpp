#include "makeMaps.h"
#include "minHeap.h"
#include "Node.h"
#include <iostream>

makeMaps::makeMaps(){
  //initialize the encode map to negative 10 and decode to ascii key to char value
  int i=97;
  for(char c=97; c<123; c++){
    encode[c]="";
    //decode[i]=c;
    //i++;
  }
  encode[32]="";
  //decode[32]=32;
}/*
void makeMaps::makeEncode(std::string file){
  encoding="";
  Node* search=hoff;
  while(search->getLetter()=='!'){
    search->getLchild();
    encoding+="1";
  }
  encode[search->getLetter()]=encoding;

  //if it was the left child, go to the right child

  if(search->getParent()->getLchild()==search){
    encoding=encoding-"1";
    search->getRchild();
    encoding+="0";
  }
  }*/
void makeMaps::printTrie(Node *n) {
  if (n->getLchild() != NULL) {
    printTrie(n->getLchild());
  }
  if (n->getLetter() != '!')
    std::cout << n->getLetter() << ": " << n->getFrequency() << std::endl;
  if (n->getRchild() != NULL) {
    printTrie(n->getRchild());
  }
}
void makeMaps::makeEncode(std::string file){
  //call the constructor to make the heap using the file and then call makeOne to make the one segment then call getHoff to get the segment then call encode to make the encoding for each letter
  minHeap* heap=new minHeap(file);           //heapified the letters
  heap->toString();
  heap->makeOne();
  Node* hoff=heap->getHoff();            //I should have the one node that has a bunch of children that I can encode
  encodeHelper(hoff);
  for (char i = 97; i<123; i++) {
    std::cout << i << ": " << encode[i] << std::endl;
  }
  char x = 32;
  std::cout << x << ": " << encode[x] << std::endl;
  printTrie(hoff);
}

void makeMaps::makeDecode(){          //from encode map
  for(char c=97;c<123;c++){
    decode[encode[c]]=c;
  }
    decode[encode[32]]=32;
}

void makeMaps::encodeHelper(Node * root) {
  if (root->getLchild() != NULL) {
    encodeHelper(root->getLchild());
  }
  if (root->getLetter() != '!') {
    encode[root->getLetter()] = root->getCode();
  }
  if (root->getRchild() != NULL) {
    encodeHelper(root->getRchild());
  }
}

std::string makeMaps::makeEncodedString(std::string input){
  std::string result="";
  for(int i=0; i<input.length(); i++){
    result+=encode[input[i]];
  } 
  return result;
}
std::string makeMaps::makeDecodedString(std::string input){
  std::string result="";
  std::string isCode="";
  for(int i=0; i<input.length(); i++){
    isCode+=input[i];
    if(decode.find(isCode) != decode.end()) {
      result += decode[isCode];
      isCode = "";
    }
  }
  return result;
}
