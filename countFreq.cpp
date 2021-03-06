#include "countFreq.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

countFreq::countFreq(){
  //for every letter, set that to 0
  for(char i=97; i<123; i++){
    Node* input= new Node(i, 0);
    arrOfFreq[i-97]=input;
  }
  //insert a spot for ' '
  arrOfFreq[26]=new Node(32, 0);
}

void countFreq::addLetters(std::string file){

  for(int i=0; i<file.length();i++){
    if(file[i] == 32) arrOfFreq[26]->setFrequency((arrOfFreq[26]->getFrequency())+1);
    else{
      int x=file[i]-97;
      arrOfFreq[x]->setFrequency(arrOfFreq[x]->getFrequency()+1);
    }
  }
}



void countFreq::print(){
  for(int i = 0; i<27; i++) {
    if(arrOfFreq[i]->getFrequency()!=0){
      std::cout<<arrOfFreq[i]->getLetter()<<": "<<arrOfFreq[i]->getFrequency()<<std::endl;
    }
  }
}

int countFreq::getValueAt(int i){
  return arrOfFreq[i]->getFrequency();
}

Node* countFreq::getNode(int index){
  return arrOfFreq[index];
}
