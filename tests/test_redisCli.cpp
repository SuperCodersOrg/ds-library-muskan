#include<iostream>
#include<string>
#include "../include/RedisCli/RedisCli.h"
int main(){
  // std::string name;
  // getline(std::cin,name);
  // std::cout<<name.size();
  RedisCli<int,std::string> r;
  r.run();
  return 0;
}