#include "countFreq.h"
#include "minHeap.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
  countFreq frequencies;
  frequencies.addLetters("plain_input.txt");
  frequencies.printMap();

  std::cout<<"\n\n"<<std::endl;

  minHeap heap("plain_input.txt");
  heap.toString();


}

