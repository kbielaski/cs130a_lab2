#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

minHeap::minHeap(std::string file) {
  heapify(file);
}

Node* minHeap::getMin(){
  Node * min = heap.at(1);
  heap.at(1) = heap.back();
  heap.pop_back();
  percolateDown(1);
  return min; 
}

void minHeap::heapify(std::string file){
  //this adds all the letters from a file into a vector with nodes of the letter and frequency
  countFreq freqTable;
  freqTable.addLetters(file);
  freqTable.print();
  Node* zero= new Node('?',-100);
  heap.push_back(zero);
  for(int i=0; i<27; i++){
    if(freqTable.getValueAt(i)!=0){
      int frequency = freqTable.getValueAt(i);
      Node* newNode = new Node();
      newNode->setLetter(freqTable.getNode(i)->getLetter());
      newNode->setFrequency(frequency);
      heap.push_back(newNode);
    }
  }
  //now I need to do the heapifying
  for(int i=(heap.size()-1)/2;i>0;i--){
    percolateDown(i);}
}


void minHeap::insert(Node * toInsert){
  heap.push_back(toInsert);
  percolateUp();
}

void minHeap::percolateUp() {
  int p = heap.size()-1;
  while (p > 0) {
    if (heap[p/2]->getFrequency() > heap[p]->getFrequency()) {
      swapNodes(p/2, p);
      p = p/2;
    }
    else {
      break;
    }
  }
}

void minHeap::percolateDown(int index) {
  while(layerabove(index)) {                                                             //layer above checks to make sure that there exists children
    if (heap[index]->getFrequency() > heap[2*index]->getFrequency() && 
	heap[index]->getFrequency() > heap[2*index + 1]->getFrequency()) {
      if (heap[2*index]->getFrequency() < heap[2*index+1]->getFrequency()) {
	swapNodes(index, 2*index);
	index = index*2;
      }
      else {
	swapNodes(index, 2*index+1);
	index = 2*index+1;
      }
    }
    if(layerabove(index)){                                                                     //checks the condition again
      if (heap[index]->getFrequency() > heap[2*index]->getFrequency() ^                   //exclusive or so that it will only go through one
	  heap[index]->getFrequency() > heap[2*index+1]->getFrequency()) {
	if (heap[2*index]->getFrequency() < heap[index]->getFrequency()) {
	  swapNodes(index, 2*index);
	  index = index*2;
	}
	else {
	  swapNodes(index, 2*index+1);
	  index = 2*index+1;
	}
      }
    }
    //at the end of the while loop, if the parent is less than the children then break
    if(layerabove(index)){
      if(heap[index]->getFrequency()<=heap[index*2]->getFrequency()&&heap[index]->getFrequency()<=heap[index*2+1]->getFrequency())
	break;}
  }
}

void minHeap::swapNodes(int i, int j){
  Node* temp = new Node();
  temp->copyNode(heap[i]);
  heap[i]->copyNode(heap[j]);
  heap[j]->copyNode(temp);
  delete temp;
}

void minHeap::toString(){
  std::string result="";
  for(int i=0; i<heap.size();i++){

    result+="(";
    result+=heap[i]->getLetter();
    result+=",";
    int a=heap[i]->getFrequency();
    stringstream ss;
    ss<<a;
    string str =ss.str();
    result+=str;
    result+=")";
  }
  std::cout << result << std::endl;
}

Node * minHeap::connect(Node* min1, Node* min2) {
  int newFreq = min1->getFrequency() + min2->getFrequency();
  Node * newParent = new Node(newFreq);
  newParent->setLchild(min2);
  encode(min2, "1");
  newParent->setRchild(min1);
  encode(min1, "0");
  return newParent;
}

//do we need to add 1's and 0's to toAdd whether it is going left or right?
void minHeap::encode(Node * n, std::string toAdd) {
  if (n->getLchild() == NULL) {
    return;
  }
  if (n->getLetter() != '!') {
    n->addToCode(toAdd);
  }
  encode(n->getLchild(), toAdd);
  encode(n->getRchild(), toAdd);
}

bool minHeap::layerabove(int index){                                 //layer above the last points to something still in the heap
  if(heap.size()%2==0 && 2*index+1<=heap.size()-1){                     //if the size of the heap is even
    return true;}
  if(heap.size()%2!=0 && 2*index<=heap.size()-1)
    return true;
  else
    return false;
}

void minHeap::makeOne(){
  while(heap.size()>2){
    Node* minone=getMin();
    Node* mintwo=getMin();
    Node* combo=connect(minone, mintwo);
    insert(combo);
  }
}

Node* minHeap::getHoff(){
  return heap[1];
}
