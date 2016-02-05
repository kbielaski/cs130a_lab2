#include "countFreq.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
  countFreq frequencies;
  frequencies.addLetters("plain_input.txt");
  std::cout<< "i get to here"<<std::endl;
  frequencies.printMap();
}

