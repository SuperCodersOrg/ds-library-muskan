#include<iostream>
#include "../include/HashMap/HashMap.h"
using namespace std;
int main(){
  HashMap h(10);
  h.set(10,"muskan1");
  h.set(10,"Neha");
  h.set(20,"muskan2");
  h.set(30,"muskan3");
  h.set(40,"muskan4");
  h.set(50,"muskan5");
  h.set(11,"verma1");
  h.set(21,"verma2");
  cout<<h.exist(22)<<"\n"<<h.exist(20);
  // h.print();
  
  h=h;
  

  // h.print();
  h.print();
  // cout<<h.getCapacity()<<"\n"<<h.getCapacity();
  return 0;
}