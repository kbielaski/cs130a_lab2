#include "Node.h"
#include "countFreq.h"
#include <iostream>

Node::Node(){
  this->letter='!';
  this->frequency=0;
  this->code = "";
}

Node::Node(int frequency){
  this->letter='!';
  this->frequency=frequency;
  this->code = "";
}

Node::Node(char letter, int frequency){
  this->letter=letter;
  this->frequency=frequency;
  this->code = "";
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

Node * Node::getParent() {
  return parent;
}

void Node::setLchild(Node * lchild) {
  this->lchild = lchild;
}

void Node::setRchild(Node * rchild) {
  this->rchild = rchild;
}

void Node::setParent(Node * parent) {
  this->parent = parent;
}

void Node::setCode(std::string code) {
  this->code = code;
}

std::string Node::getCode() {
  return code;
}