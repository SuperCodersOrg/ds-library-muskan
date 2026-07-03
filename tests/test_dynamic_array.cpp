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
  DynamicArray<string> d2;
  d2=d;
  d2.insert(4,"max");
  for(int i=0;i<5;i++){
    cout<<d.get(i)<<" ";
  }
  for(int i=0;i<5;i++){
    cout<<d2.get(i)<<" ";
  }
  return 0;
}