#include<iostream>
#include<string>
#include "../include/DynamicArray/DynamicArray.h"
using namespace std;
int main(){
  DynamicArray<string> d;
  d.append("hello");
  d.append("my");
  d.append("name");
  d.append("is");
  d.append("john");
  for(int i=0;i<5;i++){
    cout<<d.get(i)<<" ";
  }
  return 0;
}