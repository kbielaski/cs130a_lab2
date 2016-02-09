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
void minHeap::maintainInvariant(){

  for(int i=heap.size()/2; i>0; i--){
    p=index;
    while(heap[p*2]->getFrequency()<heap[p]->getFrequency()||
	  heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){                 //when the children are less than the parent then swap them 
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()&&                    //when both children are less than the parent, compare them
	 heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
	if(heap[p*2]->getFrequency()<heap[p*2+1]->getFrequency()){
	  heap[p*2]->swap(freqTable[p]);
	  p=p*2;
	}
	else{
	  heap[p*2+1]->swap[freqTable[p]);
	  p=p*2+1;
	}
      }
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()){
	heap[p*2]->swap(freqTable[p]);
	p=p*2;
      }
      else {
	heap[p*2+1]->swap(freqTable[p]);
	p=p*2+1;
      }
    }}
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
    
  maintainInvariant(i);
    

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
