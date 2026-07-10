#include<iostream>
#include<string>
#include "../include/RedisCli/RedisCli.h"
int main(){
// =====================================================
// ===== Method: Default Constructor ===================
// =====================================================

// Test Case 1: Create RedisCli object
{
    RedisCli<int,int> redis;
}
// Expected:
// Object created successfully.
// No output.
// No crash.


// Test Case 2: Create RedisCli with string types
{
    RedisCli<std::string,std::string> redis;
}
// Expected:
// Object created successfully.
// No output.


// Test Case 3: Multiple RedisCli objects
{
    RedisCli<int,int> r1;
    RedisCli<int,int> r2;
    RedisCli<int,int> r3;
}
// Expected:
// All objects created successfully.


// Test Case 4: Constructor + immediate run then EXIT
{
    RedisCli<std::string,std::string> redis;

    // Input:
    // EXIT
    redis.run();
}
// Expected:
// REDIS:
// Program exits immediately.


// Test Case 5: Create object inside a scope
{
    {
        RedisCli<int,int> redis;
    }

    std::cout<<"Done"<<std::endl;
}
// Expected:
// Done
//
// No crash while leaving the scope.
  return 0;
}