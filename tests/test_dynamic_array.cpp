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
  d.append("hello");
  d.append("my");
  d.append("name");
  d.append("is");
  d.append("max");
   d.append("hello");
  d.append("my");
  d.append("name");
  d.append("is");
  d.append("Jessi");
  for(int i=0;i<15;i++){
    cout<<d.get(i)<<" ";
  }
  return 0;
}