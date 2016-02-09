#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <vector>
#include <string>

minHeap::minHeap(std::string file) {
	heapify(file);
}
Node* minHeap::getMin(){
	Node * min = heap.at(1);
	heap.at(1) = heap.back();
	heap.pop_back();
	maintainInvariant();
	return min; 
}

void minHeap::heapify(std::string file){
  //this adds all the letters from a file into a vector with nodes of the letter and frequency
  countFreq * freqTable = new countFreq();
  Node* zero= new Node('?',-100);
  heap[0]=zero;
  freqTable->addLetters(file);
    for(char i=97; i<=123; i++){
      if(freqTable->getValue(i)!=0){      
	     Node * p=new Node(i, freqTable->getValue(i));
	     heap.push_back(p);
      }
    }
    if(freqTable->getValue(46)!=0){
      Node * p=new Node(46, freqTable->getValue(46));
      heap.push_back(p);}

    if(freqTable->getValue(32)!=0){
      Node * p=new Node(32, freqTable->getValue(32));
      heap.push_back(p);}

    if(freqTable->getValue(10)!=0){
      Node * p=new Node(10, freqTable->getValue(10));
      heap.push_back(p);}
    //now I need to do the heapifying


}
void minHeap::insert(Node * toInsert){
	heap.push_back(toInsert);
	maintainInvariant();
}

void minHeap::maintainInvariant() {
  for(int i=heap.size(); i<0;i--){
    int p=i/2;
    while(heap[p*2]->getFrequency()<heap[p]->getFrequency()||
          heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()&&
         heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
        if(heap[p*2]->getFrequency()<heap[p*2+1]->getFrequency()){
            swap(p*2,p);
            p=p*2;
          }
        else{
          swap(p*2+1,p);
          p=p*2+1;
        }
      }
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()){
        swap(p*2,p);
       p=p*2;
    }
      else{
        swap(p*2+1,p);
        p=p*2+1;
      }
    }
  }
}
void minHeap::swap(int i, int j){
Node* temp=heap[i];
heap[i]=heap[j];
heap[j]=temp;

}

void minHeap::toString(){
  std::string result="";
  for(int i=0; i<heap.size();i++){
    result+="(";
    result+=heap[i]->getLetter();
    result+=",";
    result+=heap[i]->getFrequency();
    result+=")";
  }
  std::cout << result << std::endl;
}

Node * minHeap::connect(Node* min1, Node* min2) {
	int newFreq = min1->getFrequency() + min2->getFrequency();
	Node * newParent = new Node(newFreq);
	newParent->setLchild(min1);
	newParent->setRchild(min2);
	min1->setParent(newParent);
	min2->setParent(newParent);
	return newParent;
}
