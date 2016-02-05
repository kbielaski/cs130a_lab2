#include "countFreq.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>

countFreq::countFreq(){
  //for every letter, set that to 0
  for(int i=97; i<123; i++)
    table.insert(std::pair<char, int>(i,0));

  //insert a spot for '.', ' ', '\n'
  table.insert(std::pair<char, int>(46, 0));
  table.insert(std::pair<char, int>(32, 0));
  table.insert(std::pair<char, int>(10, 0));
}

countFreq::~countFreq(){

}


void countFreq::addLetters(std::string file){
  freopen(file.c_str(),"r",stdin);    //read in file
  char x;
  std::cin >>x;
  while(true){
    if(std::cin.eof())
      {
	break;
      }
    else
      {            // i think the error is somewhere in here
	std::map<char, int>::iterator p;
	p=table.find(x);
	std::cout<< p->second<<std::endl;
	if(p!=table.end())
	  p->second++;
      }
  }
}

void countFreq::printMap(){
  std::map<char, int>::iterator it;
  for(it=table.begin(); it!=table.end(); it++){
    if(it->first!=0)
      std::cout<<it->first<<": "<<it->second<<std::endl;
  }
}

int countFreq::getValue(char c){
  std::map<char, int>::iterator p;
  p=table.find(c);
  if(p!=table.end())
    return p->second;
}
