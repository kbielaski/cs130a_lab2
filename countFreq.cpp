#include "countFreq.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

countFreq::countFreq(){
  int j=0;
  //for every letter, set that to 0
  for(char i=97; i<=123; i++){
    Node* input= new Node(i, 0);
    arrOfFreq[j]=input;
    j++;
  }
  //insert a spot for ' '
  arrOfFreq[27]=new Node(32, 0);

}

void countFreq::addLetters(std::string file){
  freopen(file.c_str(),"r",stdin);    //read in file
  char x;
  while(true){
    std::cin>>x;
    if(std::cin.eof())
      {
        break;
      }
        if(x==32) arrOfFreq[27]->setFrequency((arrOfFreq[27]->getFrequency())+1);
      else{
        x=x-97;
        arrOfFreq[x]->setFrequency(arrOfFreq[x]->getFrequency()+1);
      }
  }
}



void countFreq::print(){
  for(int i = 0; i<=28; i++) {
    if(arrOfFreq[i]->getFrequency()!=0)
      std::cout<<arrOfFreq[i]->getLetter()<<": "<<arrOfFreq[i]->getFrequency()<<std::endl;
  }
}

int countFreq::getValue(int c){
  return arrOfFreq[c]->getFrequency();
}

Node* countFreq::getNode(int index){
  return arrOfFreq[index];
}
