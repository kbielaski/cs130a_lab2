#include "minHeap.h"
#include "Node.h"
#include "vectOfNode.h"
#include <iostream>


minHeap::minHeap(){


}
void minHeap::deleteMin(){

}
void minHeap::heapify(){

}
void minHeap::insert(){

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
