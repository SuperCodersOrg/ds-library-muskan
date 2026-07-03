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



// // ===== Method: getCapacity() =====

// // Test 1: default constructor
// DynamicArray<int> arr21;
// std::cout << arr21.getCapacity() << std::endl;

// // Expected: 0


// // Test 2: parameterized constructor
// DynamicArray<int> arr22(5);
// std::cout << arr22.getCapacity() << std::endl;

// // Expected: 5


// // Test 3: after first append (default allocates 10)
// DynamicArray<int> arr23;
// arr23.append(10);

// std::cout << arr23.getCapacity() << std::endl;

// // Expected: 10


// // Test 4: after regrow
// DynamicArray<int> arr24;
// for(int i=1;i<=11;i++){
//     arr24.append(i);
// }

// std::cout << arr24.getCapacity() << std::endl;

// // Expected: 20


// // Test 5: after shrink
// DynamicArray<int> arr25;
// for(int i=1;i<=10;i++){
//     arr25.append(i);
// }
// for(int i=0;i<8;i++){
//     arr25.remove(0);
// }

// std::cout << arr25.getCapacity() << std::endl;

// // Expected: 5



// ===== Method: Copy Constructor =====

// // Test 1: copy empty array
// DynamicArray<int> arr1;
// DynamicArray<int> copy1(arr1);

// std::cout << copy1.getSize() << " " << copy1.getCapacity() << std::endl;

// // Expected: 0 0


// // Test 2: copy one element
// DynamicArray<int> arr2;
// arr2.append(10);

// DynamicArray<int> copy2(arr2);

// std::cout << copy2.get(0) << " " << copy2.getSize() << std::endl;

// // Expected: 10 1


// // Test 3: copy multiple elements
// DynamicArray<int> arr3;
// arr3.append(1);
// arr3.append(2);
// arr3.append(3);

// DynamicArray<int> copy3(arr3);

// std::cout << copy3.get(0) << " " << copy3.get(1) << " " << copy3.get(2) << std::endl;

// // Expected: 1 2 3


// // Test 4: deep copy check
// DynamicArray<int> arr4;
// arr4.append(10);
// arr4.append(20);

// DynamicArray<int> copy4(arr4);

// arr4.remove(0); // modify original

// std::cout << copy4.get(0) << " " << copy4.get(1) << std::endl;

// // Expected: 10 20


// // Test 5: deep copy address check
// DynamicArray<int> arr5;
// arr5.append(50);

// DynamicArray<int> copy5(arr5);

// std::cout << &arr5.get(0) << std::endl;
// std::cout << &copy5.get(0) << std::endl;

// // Expected: Different addresses



// // ===== Method: Assignment Operator =====

// // Test 1: assign empty to empty
// DynamicArray<int> arr6;
// DynamicArray<int> arr7;

// arr7 = arr6;

// std::cout << arr7.getSize() << " " << arr7.getCapacity() << std::endl;

// // Expected: 0 0


// // Test 2: assign one element
// DynamicArray<int> arr8;
// arr8.append(10);

// DynamicArray<int> arr9;
// arr9 = arr8;

// std::cout << arr9.get(0) << " " << arr9.getSize() << std::endl;

// // Expected: 10 1


// // Test 3: assign multiple elements
// DynamicArray<int> arr10;
// arr10.append(1);
// arr10.append(2);
// arr10.append(3);

// DynamicArray<int> arr11;
// arr11 = arr10;

// std::cout << arr11.get(0) << " " << arr11.get(1) << " " << arr11.get(2) << std::endl;

// // Expected: 1 2 3


// // Test 4: deep copy check after assignment
// DynamicArray<int> arr12;
// arr12.append(100);
// arr12.append(200);

// DynamicArray<int> arr13;
// arr13 = arr12;

// arr12.remove(0); // modify original

// std::cout << arr13.get(0) << " " << arr13.get(1) << std::endl;

// // Expected: 100 200


// // Test 5: self-assignment
// DynamicArray<int> arr14;
// arr14.append(7);
// arr14.append(8);

// arr14 = arr14;

// std::cout << arr14.get(0) << " " << arr14.get(1) << " " << arr14.getSize() << std::endl;

// // Expected: 7 8 2



// // ===== Method: Destructor =====

// // Test 1: normal destruction (scope ends)
// {
//     DynamicArray<int> arr15;
//     arr15.append(10);
//     arr15.append(20);
// }
// // Expected: object destroyed without crash


// // Test 2: destroy empty array
// {
//     DynamicArray<int> arr16;
// }
// // Expected: no crash


// // Test 3: destroy string objects
// {
//     DynamicArray<std::string> arr17;
//     arr17.append("hello");
//     arr17.append("world");
// }
// // Expected: string destructors called correctly


// // Test 4: destroy after regrow
// {
//     DynamicArray<int> arr18;
//     for(int i=1;i<=15;i++){
//         arr18.append(i);
//     }
// }
// // Expected: all elements cleaned, no leak


// // Test 5: destroy after shrink
// {
//     DynamicArray<int> arr19;
//     for(int i=1;i<=10;i++){
//         arr19.append(i);
//     }
//     for(int i=0;i<8;i++){
//         arr19.remove(0);
//     }
// }
// // Expected: remaining elements cleaned, no leak



// ===== Edge Case / Stress Tests =====

// Test 1: append many elements (multiple regrows)
DynamicArray<int> arr20;
for(int i=1;i<=100;i++){
    arr20.append(i);
}
std::cout << arr20.getSize() << " " << arr20.getCapacity() << std::endl;

// Expected: 100 (capacity should be >=100)


// Test 2: remove all elements
DynamicArray<int> arr21;
for(int i=1;i<=10;i++){
    arr21.append(i);
}
for(int i=0;i<10;i++){
    arr21.remove(0);
}
std::cout << arr21.getSize() << " " << arr21.getCapacity() << std::endl;

// Expected: 0 0


// Test 3: insert repeatedly at front
DynamicArray<int> arr22;
for(int i=1;i<=5;i++){
    arr22.insert(0, i);
}
for(int i=0;i<arr22.getSize();i++){
    std::cout << arr22.get(i) << " ";
}
std::cout << std::endl;

// Expected: 5 4 3 2 1


// Test 4: alternate append/remove
DynamicArray<int> arr23;
arr23.append(10);
arr23.remove(0);
arr23.append(20);
arr23.append(30);
arr23.remove(1);

std::cout << arr23.get(0) << " " << arr23.getSize() << std::endl;

// Expected: 20 1


// Test 5: copy + assignment chain
DynamicArray<int> arr24;
arr24.append(1);
arr24.append(2);

DynamicArray<int> arr25(arr24);
DynamicArray<int> arr26;
arr26 = arr25;

arr24.remove(0);

std::cout << arr25.get(0) << " " << arr26.get(0) << std::endl;

// Expected: 1 1
}