<<<<<<< HEAD

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
  code = s + code;
}
=======
#ifndef NODE_H
#define NODE_H

#include <string>

class Node{
 public:
  Node();
  Node(int frequency);
  Node(char letter, int frequency);
  Node(char letter, int frequency, std::string code);
  void copyNode(Node*n);
  char getLetter();
  int getFrequency();
  void setFrequency(int frequency);
  void setLetter(char letter);
  Node * getLchild();
  Node * getRchild();
  Node * getParent();
  void setLchild(Node * lchild);
  void setRchild(Node * rchild);
  void setParent(Node * parent);
  void setCode(std::string code);
  std::string getCode();
  void addToCode(std::string s);
  
 private:
  char letter;          //if it is a connecting node then make the letter '!'
  int frequency;
  std::string code;
  Node* lchild;
  Node* rchild;
};

#endif
>>>>>>> abe9b31d55abcb8c72b3bb34a5ed7c97c461a6fd
