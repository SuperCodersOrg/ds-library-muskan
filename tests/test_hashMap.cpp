#include<iostream>
#include "../include/HashMap/HashMap.h"
using namespace std;
int main(){
  HashMap h;
  h.set(10,"muskan");
  h.set(11,"verame");
  cout<<h.get(10)<<" "<<h.get(11);
  return 0;
}