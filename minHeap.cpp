#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <vector>
#include <string>

minHeap::minHeap(){


}
void minHeap::deleteMin(){

}
void minHeap::heapify(std::string file){
  //this adds all the letters from a file into a vector with nodes of the letter and frequency
  countFreq freqTable=new freqTable();
  freqTable.addLetters(file);
    for(char i=97; i<=123; i++){
      if(freqTable.getValue(i)!=0){      
	Node p=new Node(i, freqTable.getValue(i));
	heap.emplace_back(p);
      }}
    if(freqTable.getValue(46)!=0){
      Node p=new Node(46, freqTable.getValue(46));
      heap.emplace_back(p);}

    if(freqTable.getValue(32)!=0){
      Node p=new Node(32, freqTable.getValue(32));
      heap.emplace_back(p);}

    if(freqTable.getValue(10)!=0){
      Node p=new Node(10, freqTable.getValue(10));
      heap.emplace_back(p);}
    //now I need to do the heapifying


}
void minHeap::insert(){

}
void minHeap::connect(){

}
