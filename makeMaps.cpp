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

void makeMaps::makeEncode(std::string file){
  //call the constructor to make the heap using the file and then call makeOne to make the one segment then call getHoff to get the segment then call encode to make the encoding for each letter
  minHeap* heap=new minHeap(file);           //heapified the letters
  heap->makeOne();
  Node* hoff=heap->getHoff();            //I should have the one node that has a bunch of children that I can encode
  std::cout << hoff->getFrequency() << std::endl;
  encodeHelper(hoff);
}

void makeMaps::makeDecode(){          //from encode map
  for(char c=97;c<123;c++){
    decode[encode[c]]=c;
  }
    decode[encode[32]]=32;
}

void makeMaps::encodeHelper(Node * root) {
  std::cout<<"entered encodeHelper"<<std::endl;
  while (root->getLchild() != NULL) {
    std::cout<<root->getLetter()<<" "<<root->getFrequency()<<std::endl;
    encodeHelper(root->getLchild());
  }
  if (root->getLetter() != '!') {
    encode[root->getLetter()] = root->getCode(); 
  }
  while (root->getRchild() != NULL) {
    encodeHelper(root->getRchild());
  }
  std::cout<<"end of encode Helper"<<std::endl;
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
