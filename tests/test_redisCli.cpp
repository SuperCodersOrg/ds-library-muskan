#include<iostream>
#include<string>
#include "../include/RedisCli/RedisCli.h"
int main(){
// // =====================================================
// // ===== Method: Default Constructor ===================
// // =====================================================

// // Test Case 1: Create RedisCli object
// {
//     RedisCli<int,int> redis;
// }
// // Expected:
// // Object created successfully.
// // No output.
// // No crash.


// // Test Case 2: Create RedisCli with string types
// {
//     RedisCli<std::string,std::string> redis;
// }
// // Expected:
// // Object created successfully.
// // No output.


// // Test Case 3: Multiple RedisCli objects
// {
//     RedisCli<int,int> r1;
//     RedisCli<int,int> r2;
//     RedisCli<int,int> r3;
// }
// // Expected:
// // All objects created successfully.


// // Test Case 4: Constructor + immediate run then EXIT
// {
//     RedisCli<std::string,std::string> redis;

//     // Input:
//     // EXIT
//     redis.run();
// }
// // Expected:
// // REDIS:
// // Program exits immediately.


// // Test Case 5: Create object inside a scope
// {
//     {
//         RedisCli<int,int> redis;
//     }

//     std::cout<<"Done"<<std::endl;
// }
// // Expected:
// // Done
// //
// // No crash while leaving the scope.




// =====================================================
// ===== Method: Copy Constructor =======================
// =====================================================

// Test Case 1: Copy an empty RedisCli
{
    RedisCli<int,int> r1;

    RedisCli<int,int> r2(r1);
}
// Expected:
// Copy succeeds.
// No crash.


// Test Case 2: Copy and run copied object
{
    RedisCli<std::string,std::string> r1;

    RedisCli<std::string,std::string> r2(r1);

    // Input:
    // EXIT
    r2.run();
}
// Expected:
// REDIS:
// Program exits normally.


// Test Case 3: Copy multiple times
{
    RedisCli<int,int> r1;

    RedisCli<int,int> r2(r1);

    RedisCli<int,int> r3(r2);
}
// Expected:
// All copies created successfully.
// No crash.


// Test Case 4: Copy inside nested scope
{
    RedisCli<int,int> r1;

    {
        RedisCli<int,int> r2(r1);
    }

    std::cout<<"OK"<<std::endl;
}
// Expected:
// OK
// No double free.


// Test Case 5: Copy temporary object
{
    RedisCli<int,int> r1;

    RedisCli<int,int> r2 = r1;
}
// Expected:
// Copy constructor called.
// No crash.
  return 0;
}