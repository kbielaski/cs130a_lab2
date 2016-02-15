#include "makeMaps.h"
#include "minHeap.h"
#include "Node.h"
#include <iostream>

makeMaps::makeMaps(){
  //initialize the encode map to negative 10 and decode to ascii key to char value
  int i=97;
  for(char c=97; c<123; c++){
    encode[c]=-10;
    decode[i]=c;
    i++;
  }
  encode[32]=-10;
  decode[32]=32;
}
void makeMaps::makeEncode(std::string file){
  //call the constructor to make the heap using the file and then call makeOne to make the one segment then call getHoff to get the segment then call encode to make the encoding for each letter
  minHeap* heap=new minHeap(file);           //heapified the letters
  heap->makeOne();
  Node* hoffTree=heap->getHoff();            //I should have the one node that has a bunch of children that I can encode

}
void makeDecode(){          //from encode map

}
