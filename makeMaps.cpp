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
  encodeHelper(hoff);
}

void makeMaps::makeDecode(){          //from encode map
  for(char c=97;c<123;c++){
    decode[encode[c]]=c;
  }
    decode[encode[32]]=32;
}

void makeMaps::encodeHelper(Node * root) {

  while (root->getLchild() != NULL) {
    encodeHelper(root->getLchild());
  }
  if (root->getLetter() != '!') {
    encode[root->getLetter()] = root->getCode(); 
  }
  while (root->getRchild() != NULL) {
    encodeHelper(root->getRchild());
  }
}