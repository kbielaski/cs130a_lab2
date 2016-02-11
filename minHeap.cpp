#include "minHeap.h"
#include "Node.h"
#include "countFreq.h"
#include <iostream>
#include <string>

minHeap::minHeap(std::string file) {
  amount=0;
  heapify(file);
}
Node* minHeap::getMin(){
  Node * min = heap[1];
  //heap[1] = heap.back();
  //heap.pop_back();
  maintainInvariant();
  return min; 
}
void minHeap::heapify(std::string file){
  //this adds all the letters from a file into a vector with nodes of the letter and frequency
  amount = 0;
  countFreq * freqTable = new countFreq();
  freqTable->addLetters(file);
  Node* zero= new Node('?',-100);
  heap[0]=zero;
  amount++;
  int nextSpot=1;
  for(int i=0; i<28; i++){
    std::cout<<"gets here"<<std::endl;
    if(freqTable->getValue(i+97)!=0||freqTable->getValue(32)!=0){
      heap[nextSpot]=freqTable->getNode(i);
      nextSpot++;
      amount++;
    }
  }
  //now I need to do the heapifying
  for(int i=(amount-1)/2; i<0;i--)
    percolateDown(i);
}


void minHeap::insert(Node * toInsert){
  //heap.push_back(toInsert);
  maintainInvariant();
}
//i think that my problem is that I am comparing places in the vector that don't contain anything
void minHeap::percolateUp(){
  for(int p=(amount-1)/2; p<0;p=p/2){
    if(heap[p*2]->getFrequency()<heap[p]->getFrequency()||
	  heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()&&
	 heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
	if(heap[p*2]->getFrequency()==heap[p*2+1]->getFrequency()){
	  swapNodes(p*2+1,p);
	}
	if(heap[p*2]->getFrequency()<heap[p*2+1]->getFrequency()){
	  swapNodes(p*2,p);
	}
	else{
	  swapNodes(p*2+1,p);
	}
      }
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()){
	swapNodes(p*2,p);
      }
      else{
	swapNodes(p*2+1,p);
      }
    }
  }
}


void minHeap::percolateDown(int index) {
  for(int p=index; p<(amount-1);){
    if(heap[p*2]->getFrequency()<heap[p]->getFrequency()||
          heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()&&
         heap[p*2+1]->getFrequency()<heap[p]->getFrequency()){
	if(heap[p*2]->getFrequency()==heap[p*2+1]->getFrequency()){
          swapNodes(p*2+1,p);
	  p=p*2+1;
        }
        if(heap[p*2]->getFrequency()<heap[p*2+1]->getFrequency()){
          swapNodes(p*2,p);
          p=p*2;
        }
        else{
          swapNodes(p*2+1,p);
          p=p*2+1;
        }
      }
      if(heap[p*2]->getFrequency()<heap[p]->getFrequency()){
        swapNodes(p*2,p);
        p=p*2;
      }
      else{
        swapNodes(p*2+1,p);
        p=p*2+1;
      }
    }
  }
}

void minHeap::swapNodes(int i, int j){
  Node* temp=heap[i];
  heap[i]=heap[j];
  heap[j]=temp;

}

void minHeap::toString(){
  std::string result="";
  for(int i=0; i<(amount-1);i++){
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
  newParent->setLchild(min2);
  encode(min2, "1");
  newParent->setRchild(min1);
  encode(min1, "0");
  return newParent;
}

void minHeap::encode(Node * n, std::string toAdd) {
  if (n->lchild == NULL) {
    return;
  }
  if (n->getLetter != '!') {
    n->addToCode(toAdd);
  }
  encode(n->getLchild(), toAdd);
  encode(n->getRchild(), toAdd);
}

Node * minHeap::findInTrie(char letter, Node * root) {
  if(root->getLchild() == NULL) {
    return;
  }
  if (root->getLetter() == letter) {
    return root;
  }
  else {
    findInTrie(letter, root->getLchild());
    findInTrie(letter, root->getRchild());
}