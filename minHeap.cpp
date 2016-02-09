#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <vector>
#include <string>

minHeap::minHeap() {
	heap = new vector<Node*>;
}

minHeap::minHeap(std::string file) {
	heap = new std::vector<Node*>;
	heapify(file);
}
Node* getMin(){
	Node * min = heap.get(1);
	heap.at(1) = heap.back();
	heap.pop_back();
	maintainInvariant();
	return min; 
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
void minHeap::insert(Node * toInsert){
	heap.push_back(toInsert);
	maintainInvariant();
}

void minHeap::maintainInvariant() {

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
