#include <iostream>
#include <string>
#include "../include/DynamicArray/DynamicArray.h"
using namespace std;

int main() {
  // //Constructor test cases
  //   // Test 1
    // DynamicArray<int> arr1;
  //   cout << arr1.getSize() << " " << arr1.getCapacity() << endl;

  //   // Test 2
  //   DynamicArray<int> arr2(5);
  //   cout << arr2.getSize() << " " << arr2.getCapacity() << endl;

  //   // Test 3
  //   DynamicArray<int> arr3(100);
  //   cout << arr3.getSize() << " " << arr3.getCapacity() << endl;

  //   // Test 4
  //   try {
  //       DynamicArray<int> arr4(0);
  //   } catch(const exception& e) {
  //       cout << "Error: " << e.what() << endl;
  //   }

  //   // Test 5
  //   try {
  //       DynamicArray<int> arr5(-10);
  //   } catch(const exception& e) {
  //       cout << "Error: " << e.what() << endl;
  //   }
//append test cases
// Test 1: append into empty array
DynamicArray<int> arr1;
arr1.append(10);
std::cout << arr1.get(0) << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl;

// Test 2: append multiple values
arr1.append(20);
arr1.append(30);
std::cout << arr1.get(0) << " " << arr1.get(1) << " " << arr1.get(2) << std::endl;

// Test 3: append till exact capacity
DynamicArray<int> arr6(3);
arr6.append(1);
arr6.append(2);
arr6.append(3);
std::cout << arr6.getSize() << " " << arr6.getCapacity() << std::endl;

// Test 4: append causing regrow
arr6.append(4);
std::cout << arr6.getSize() << " " << arr6.getCapacity() << std::endl;

// Test 5: append string objects
DynamicArray<std::string> arr7;
arr7.append("hello");
arr7.append("world");
std::cout << arr7.get(0) << " " << arr7.get(1) << std::endl;
    return 0;
}