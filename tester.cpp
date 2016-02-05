#include "countFreq.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
  countFreq frequencies;
  frequencies.addLetters("plain_input.txt");
  frequencies.printMap();
}

