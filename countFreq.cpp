#include "countFreq.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>

countFreq::countFreq(){
  //for every letter, set that to 0
  for(int i=97; i<=123; i++)
    table[i]=0;

  //insert a spot for '.', ' ', '\n'
  table[46]=0;
  table[32]=0;
  table[10]=0;
}

countFreq::~countFreq(){

}


void countFreq::addLetters(std::string file){
  freopen(file.c_str(),"r",stdin);    //read in file
  char x;
  std::cin >>x;
  while(true){
    std::cout<<x<<std::endl;
    if(std::cin.eof())
      {
	break;
      }
    else
      {            // i think the error is somewhere in here
	table[x]++;
      }
  }
}

void countFreq::printMap(){
  std::map<char, int>::iterator it;
  for(int i = 97; i<=123; i++) {
    if(table[i]!=0)
      std::cout<<i<<": "<<table[i]<<std::endl;
  }
}

int countFreq::getValue(char c){
  return table[c];
}
