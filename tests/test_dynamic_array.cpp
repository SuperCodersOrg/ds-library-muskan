#include <iostream>
#include <string>
#include "../include/DynamicArray/DynamicArray.h"
using namespace std;
int main()
{
  try
  {
    // Test 1: Default constructor (positive)
    DynamicArray<int> arr1;
    std::cout << arr1.getSize() << " " << arr1.getCapacity() << std::endl;

    // Test 2: Valid capacity (positive)
    DynamicArray<int> arr2(5);
    std::cout << arr2.getSize() << " " << arr2.getCapacity() << std::endl;

    // Test 3: Large valid capacity (positive)
    DynamicArray<int> arr3(100);
    std::cout << arr3.getSize() << " " << arr3.getCapacity() << std::endl;

    // Test 4: Zero capacity (negative)
    DynamicArray<int> arr4(0);

    // Test 5: Negative capacity (negative)
    DynamicArray<int> arr5(-10);
  }
  catch (const std::exception &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}