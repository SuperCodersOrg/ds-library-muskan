#include <iostream>
#include <string>
#include "../include/DynamicArray/DynamicArray.h"
using namespace std;

int main() {
    // Test 1
    DynamicArray<int> arr1;
    cout << arr1.getSize() << " " << arr1.getCapacity() << endl;

    // Test 2
    DynamicArray<int> arr2(5);
    cout << arr2.getSize() << " " << arr2.getCapacity() << endl;

    // Test 3
    DynamicArray<int> arr3(100);
    cout << arr3.getSize() << " " << arr3.getCapacity() << endl;

    // Test 4
    try {
        DynamicArray<int> arr4(0);
    } catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 5
    try {
        DynamicArray<int> arr5(-10);
    } catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}