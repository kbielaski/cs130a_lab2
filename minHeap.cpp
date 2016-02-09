#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <vector>
#include <string>

minHeap::minHeap(){


}
Node getMin(){

}
void minHeap::deleteMin(){

}
void minHeap::maintainInvariant(int index, countFreq freqTable){
  p=index;
  while(freqTable[p*2]->getFrequency()<freqTable[p]->getFrequency()||
	freqTable[p*2+1]->getFrequency()<freqTable[p]->getFrequency()){                 //when the children are less than the parent then swap them 
    if(freqTable[p*2]->getFrequency()<freqTable[p]->getFrequency()&&                    //when both children are less than the parent, compare them
       freqTable[p*2+1]->getFrequency()<freqTable[p]->getFrequency()){
      if(freqTable[p*2]->getFrequency()<freqTable[p*2+1]->getFrequency()){
	freqTable[p*2]->swap(freqTable[p]);
	p=p*2;
      }
      else{
	freqTable[p*2+1]->swap[freqTable[p]);
	p=p*2+1;
      }
    }
    if(freqTable[p*2]->getFrequency()<freqTable[p]->getFrequency()){
      freqTable[p*2]->swap(freqTable[p]);
      p=p*2;
    }
    else {
      freqTable[p*2+1]->swap(freqTable[p]);
      p=p*2+1;
    }
 }
}
void minHeap::heapify(std::string file){
  //this adds all the letters from a file into a vector with nodes of the letter and frequency
  countFreq freqTable=new freqTable();
  Node zero=new Node('?', -100)
  freqTable.emplace_back(zero);
  freqTable.addLetters(file);
    for(char i=97; i<=123; i++){
      if(freqTable.getValue(i)!=0){      
	Node p=new Node(i, freqTable.getValue(i));
	heap.emplace_back(p);
      }}
    if(freqTable.getValue(46)!=0){
      Node p=new Node(46, freqTable.getValue(46));
      heap.emplace_back('.');}

    if(freqTable.getValue(32)!=0){
      Node p=new Node(32, freqTable.getValue(32));
      heap.emplace_back(' ');}

    if(freqTable.getValue(10)!=0){
      Node p=new Node(10, freqTable.getValue(10));
      heap.emplace_back('\n');}
    //now I need to do the heapifying

    for(int i=freqTable.size()/2; i>0; i--){
      maintainInvariant(i, freqTable);
    }

}
void minHeap::insert(){

}
Node minHeap::connect(Node* min1, Node* min2) {
	int newFreq = min1->getFrequency() + min2->getFrequency();
	Node * newParent = new Node(newFreq);
	newParent->setLchild(min1);
	newParent->setRchild(min2);
	min1->setParent(newParent);
	min2->setParent(newParent);
	return newParent;
}

std::string toString(){

}
