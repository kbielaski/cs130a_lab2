#include "countFreq.h"
#include "minHeap.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <string>
#include "makeMaps.h"
#include <fstream>

using namespace std;

int main(){
  ifstream plain("plain.input");
  string str;
  string decText="";
  while(getline(plain, str)){
    if(str!=""){
      decText+=str;
    }
  }
  ifstream encoded("encoded.input");
  string str1;
  string encText="";
  while(getline(encoded, str1)){
    if(str1!=""){
      encText+=str1;
    }
  }


}

