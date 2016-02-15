#include "countFreq.h"
#include "minHeap.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <string>
#include "makeMaps.h"

using namespace std;

int main(){
  //countFreq frequencies;
  //frequencies.addLetters("plain_input.txt");
  //frequencies.print();

  //tests constructor including heapify, swap, and percolateDown
    minHeap heap("plain_input.txt");
  heap.toString();

  //tests insert and percolateUp
  Node* one=new Node('z',2);
  heap.insert(one);
  heap.toString();

  //tests get min and delete it
  Node* two;
  Node* three;
  two=heap.getMin();
  three=heap.getMin();
  heap.toString();

  //tests connecting the two mins and inserting them
  Node* four;
  four=heap.connect(two, three);
  heap.insert(four);
  heap.toString();

  //test makeOne
  heap.makeOne();
  heap.toString();

  Node* hoff=heap.getHoff();
  //segfault in findInTrie
  Node* five= heap.findInTrie('e',hoff); 

  std::cout<<five->getLetter()<<" "<<five->getFrequency()<<std::endl;
  //test whether makeMaps gets the proper node from the heap
  /*  makeMaps madeTree;
  madeTree.makeEncode("plain_input.txt");
  */
}

