
#include "Node.h"
#include "countFreq.h"
#include <iostream>

Node::Node(){
  this->letter='!';
  this->frequency=0;
  this->code = "";
  this->lchild = NULL;
  this->rchild = NULL;
}

Node::Node(int frequency){
  this->letter='!';
  this->frequency=frequency;
  this->code = "";
  this->lchild = NULL;
  this->rchild = NULL;
}

Node::Node(char letter, int frequency){
  this->letter=letter;
  this->frequency=frequency;
  this->code = "";
  this->lchild = NULL;
  this->rchild = NULL;
}

Node::Node(char letter, int frequency, std::string code) {
  this->letter=letter;
  this->frequency=frequency;
  this->code = code;
  this->lchild = NULL;
  this->rchild = NULL;
}

void Node::copyNode(Node * n) {
  this->letter = n->getLetter();
  this->frequency = n->getFrequency();
  this->code = n->getCode();
  this->lchild = n->getLchild();
  this->rchild = n->getRchild();
}
char Node::getLetter(){
  return letter;
}
int Node::getFrequency(){
  return frequency;
}
void Node::setFrequency(int frequency){
  this->frequency=frequency;
}

void Node::setLetter(char letter){
  this->letter=letter;
}

Node * Node::getLchild() {
  return lchild;
}

Node * Node::getRchild() {
  return rchild;
}

void Node::setLchild(Node * lchild) {
  this->lchild = lchild;
}

void Node::setRchild(Node * rchild) {
  this->rchild = rchild;
}

void Node::setCode(std::string code) {
  this->code = code;
}

std::string Node::getCode() {
  return code;
}

void Node::addToCode(std::string s) {
  this->code = s + this->code;
}
