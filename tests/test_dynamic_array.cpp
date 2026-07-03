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



// //append test cases
// // Test 1: append in empty array
// DynamicArray<int> arr1;
// arr1.append(10);
// std::cout << arr1.get(0) << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl;

// // Test 2: append multiple elements
// DynamicArray<int> arr2;
// arr2.append(10);
// arr2.append(20);
// arr2.append(30);
// std::cout << arr2.get(0) << " " << arr2.get(1) << " " << arr2.get(2) << std::endl;

// // Test 3: append till exact capacity
// DynamicArray<int> arr3(3);
// arr3.append(1);
// arr3.append(2);
// arr3.append(3);
// std::cout << arr3.getSize() << " " << arr3.getCapacity() << std::endl;

// // Test 4: append causing regrow
// DynamicArray<int> arr4(3);
// arr4.append(1);
// arr4.append(2);
// arr4.append(3);
// arr4.append(4);
// std::cout << arr4.getSize() << " " << arr4.getCapacity() << std::endl;

// // Test 5: append string objects
// DynamicArray<std::string> arr5;
// arr5.append("hello");
// arr5.append("world");
// std::cout << arr5.get(0) << " " << arr5.get(1) << " " << arr5.getSize() << std::endl;



// //insert test cases
// // Test 1: insert at beginning
// DynamicArray<int> arr6;
// arr6.append(10);
// arr6.append(20);
// arr6.insert(0, 5);
// std::cout << arr6.get(0) << " " << arr6.get(1) << " " << arr6.get(2) << std::endl;

// // Test 2: insert in middle
// DynamicArray<int> arr7;
// arr7.append(10);
// arr7.append(20);
// arr7.append(30);
// arr7.insert(1, 15);
// std::cout << arr7.get(0) << " " << arr7.get(1) << " " << arr7.get(2) << " " << arr7.get(3) << std::endl;

// // Test 3: insert at end
// DynamicArray<int> arr8;
// arr8.append(10);
// arr8.append(20);
// arr8.insert(arr8.getSize(), 30);
// std::cout << arr8.get(0) << " " << arr8.get(1) << " " << arr8.get(2) << std::endl;

// // Test 4: insert causing regrow
// DynamicArray<int> arr9(2);
// arr9.append(1);
// arr9.append(2);
// arr9.insert(1, 99);
// std::cout << arr9.get(0) << " " << arr9.get(1) << " " << arr9.get(2)
//           << " " << arr9.getSize() << " " << arr9.getCapacity() << std::endl;

// // Test 5: invalid index (wrap in try-catch)
// try{
// DynamicArray<int> arr10;
// arr10.append(10);
// arr10.insert(-1, 100);
// }catch(const exception &e){
//   cout<<"Error: "<<e.what()<<endl;
// }



// // ===== Method: remove() =====

// // Test 1: remove from beginning
// DynamicArray<int> arr6;
// arr6.append(10);
// arr6.append(20);
// arr6.append(30);
// arr6.remove(0);

// std::cout << arr6.get(0) << " " << arr6.get(1) << " " << arr6.getSize() << std::endl;

// // Expected: 20 30 2


// // Test 2: remove from middle
// DynamicArray<int> arr7;
// arr7.append(10);
// arr7.append(20);
// arr7.append(30);
// arr7.remove(1);

// std::cout << arr7.get(0) << " " << arr7.get(1) << " " << arr7.getSize() << std::endl;

// // Expected: 10 30 2


// // Test 3: remove from end
// DynamicArray<int> arr8;
// arr8.append(10);
// arr8.append(20);
// arr8.append(30);
// arr8.remove(2);

// std::cout << arr8.get(0) << " " << arr8.get(1) << " " << arr8.getSize() << std::endl;

// // Expected: 10 20 2


// // Test 4: remove causing shrink
// // default append starts at 10, remove until size <= capacity/4
// DynamicArray<int> arr9;
// for(int i=1;i<=10;i++){
//     arr9.append(i);
// }
// for(int i=0;i<8;i++){
//     arr9.remove(0);
// }

// std::cout << arr9.getSize() << " " << arr9.getCapacity() << std::endl;

// // Expected: 2 5


// // Test 5: invalid remove index
// try{
//     DynamicArray<int> arr10;
//     arr10.append(10);
//     arr10.remove(5);
// }catch(const std::exception& e){
//     std::cout << e.what() << std::endl;
// }

// // Expected: Invalid remove Index



// // ===== Method: get() =====

// // Test 1: get first element
// DynamicArray<int> arr11;
// arr11.append(10);
// arr11.append(20);
// arr11.append(30);

// std::cout << arr11.get(0) << std::endl;

// // Expected: 10


// // Test 2: get middle element
// DynamicArray<int> arr12;
// arr12.append(100);
// arr12.append(200);
// arr12.append(300);

// std::cout << arr12.get(1) << std::endl;

// // Expected: 200


// // Test 3: get last element
// DynamicArray<int> arr13;
// arr13.append(5);
// arr13.append(15);
// arr13.append(25);

// std::cout << arr13.get(2) << std::endl;

// // Expected: 25


// // Test 4: get string object
// DynamicArray<std::string> arr14;
// arr14.append("hello");
// arr14.append("world");

// std::cout << arr14.get(1) << std::endl;

// // Expected: world


// // Test 5: invalid index
// try{
//     DynamicArray<int> arr15;
//     arr15.append(10);
//     arr15.get(5);
// }catch(const std::exception& e){
//     std::cout << e.what() << std::endl;
// }

// // Expected: index out of range



// // ===== Method: getSize() =====

// // Test 1: empty array
// DynamicArray<int> arr16;
// std::cout << arr16.getSize() << std::endl;

// // Expected: 0


// // Test 2: after one append
// DynamicArray<int> arr17;
// arr17.append(10);

// std::cout << arr17.getSize() << std::endl;

// // Expected: 1


// // Test 3: after multiple append
// DynamicArray<int> arr18;
// arr18.append(1);
// arr18.append(2);
// arr18.append(3);

// std::cout << arr18.getSize() << std::endl;

// // Expected: 3


// // Test 4: after insert
// DynamicArray<int> arr19;
// arr19.append(10);
// arr19.append(20);
// arr19.insert(1, 15);

// std::cout << arr19.getSize() << std::endl;

// // Expected: 3


// // Test 5: after remove
// DynamicArray<int> arr20;
// arr20.append(10);
// arr20.append(20);
// arr20.remove(0);

// std::cout << arr20.getSize() << std::endl;

// // Expected: 1



// ===== Method: getCapacity() =====

// Test 1: default constructor
DynamicArray<int> arr21;
std::cout << arr21.getCapacity() << std::endl;

// Expected: 0


// Test 2: parameterized constructor
DynamicArray<int> arr22(5);
std::cout << arr22.getCapacity() << std::endl;

// Expected: 5


// Test 3: after first append (default allocates 10)
DynamicArray<int> arr23;
arr23.append(10);

std::cout << arr23.getCapacity() << std::endl;

// Expected: 10


// Test 4: after regrow
DynamicArray<int> arr24;
for(int i=1;i<=11;i++){
    arr24.append(i);
}

std::cout << arr24.getCapacity() << std::endl;

// Expected: 20


// Test 5: after shrink
DynamicArray<int> arr25;
for(int i=1;i<=10;i++){
    arr25.append(i);
}
for(int i=0;i<8;i++){
    arr25.remove(0);
}

std::cout << arr25.getCapacity() << std::endl;

// Expected: 5
}