#include<iostream>
#include<string>
#include "../include/LinkList/LinkList.h"
using namespace std;
int main(){
LinkList<string> l;
  // for(int i=1;i<5;i++){
  //   l.insertFront(i*10);
  // }
  l.insertBack("one");
  l.insertBack("two");
  l.insertBack("three");
  l.insert(1,"1.5");
  l.insertBack("four");
  l.insertBack("five");
  cout<<l.get(3);
  // l.clear();
  cout<<l.isEmpty();
  l.print();
}