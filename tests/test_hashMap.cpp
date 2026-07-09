#include<iostream>
#include<string>
#include "../include/HashMap/HashMap.h"
using namespace std;
int main(){
//   // =====================================================
// // ===== Method: Default Constructor ===================
// // =====================================================

// // Test Case 1: Create an empty HashMap
// {
//     HashMap<int, int> map;

//     std::cout << map.getSize() << " "
//               << map.getCapacity() << std::endl;
// }
// // Expected:
// // 0 8


// // Test Case 2: Two objects should be independent
// {
//     HashMap<int, int> map1;
//     HashMap<int, int> map2;

//     map1.set(10, 100);

//     std::cout << map1.getSize() << " "
//               << map2.getSize() << std::endl;
// }
// // Expected:
// // 1 0


// // Test Case 3: Verify initial load factor
// {
//     HashMap<int, int> map;

//     std::cout << map.loadFactor() << std::endl;
// }
// // Expected:
// // 0
// // (or 0.0 depending on compiler)


// //Test Case 4: Insert immediately after construction
// {
//     HashMap<int, std::string> map;

//     map.set(1, "One");

//     std::cout << map.get(1) << std::endl;
// }
// // Expected:
// // One


// // Test Case 5: Default constructor should create 8 buckets
// {
//     HashMap<int, int> map;

//     map.print();
// }
// Expected:
// bucket1->Empty
// bucket2->Empty
// bucket3->Empty
// bucket4->Empty
// bucket5->Empty
// bucket6->Empty
// bucket7->Empty
// bucket8->Empty



// // =====================================================
// // ===== Method: Copy Constructor =======================
// // =====================================================

// // Test Case 1: Copy an empty HashMap
// {
//     HashMap<int, int> map1;

//     HashMap<int, int> map2(map1);

//     std::cout << map2.getSize() << " "
//               << map2.getCapacity() << std::endl;
// }
// // Expected:
// // 0 8


// // Test Case 2: Copy a HashMap with one element
// {
//     HashMap<int, int> map1;

//     map1.set(10, 100);

//     HashMap<int, int> map2(map1);

//     std::cout << map2.get(10) << std::endl;
//     std::cout << map2.getSize() << std::endl;
// }
// // Expected:
// // 100
// // 1


// // Test Case 3: Copy a HashMap with multiple elements
// {
//     HashMap<int, std::string> map1;

//     map1.set(1, "One");
//     map1.set(2, "Two");
//     map1.set(3, "Three");

//     HashMap<int, std::string> map2(map1);

//     std::cout << map2.get(1) << std::endl;
//     std::cout << map2.get(2) << std::endl;
//     std::cout << map2.get(3) << std::endl;
// }
// // Expected:
// // One
// // Two
// // Three


// // Test Case 4: Verify deep copy
// {
//     HashMap<int, int> map1;

//     map1.set(1, 10);
//     map1.set(2, 20);

//     HashMap<int, int> map2(map1);

//     map1.set(1, 999);

//     std::cout << map1.get(1) << std::endl;
//     std::cout << map2.get(1) << std::endl;
// }
// // Expected:
// // 999
// // 10


// // Test Case 5: Copy after rehash
// {
//     HashMap<int, int> map1;

//     for (int i = 1; i <= 20; i++)
//     {
//         map1.set(i, i * 100);
//     }

//     HashMap<int, int> map2(map1);

//     std::cout << map2.get(1) << std::endl;
//     std::cout << map2.get(10) << std::endl;
//     std::cout << map2.get(20) << std::endl;
//     std::cout << map2.getSize() << std::endl;
// }
// // Expected:
// // 100
// // 1000
// // 2000
// // 20


// // =====================================================
// // ===== Method: Parameterized Constructor =============
// // =====================================================

// // Test Case 1: Create HashMap with capacity 5
// {
//     HashMap<int, int> map(5);

//     std::cout << map.getSize() << " "
//               << map.getCapacity() << std::endl;
// }
// // Expected:
// // 0 5


// // Test Case 2: Insert one element
// {
//     HashMap<int, int> map(5);

//     map.set(10, 100);

//     std::cout << map.getSize() << " "
//               << map.getCapacity() << std::endl;
// }
// // Expected:
// // 1 5


// // Test Case 3: Verify all buckets are created
// {
//     HashMap<int, int> map(3);

//     map.print();
// }
// // Expected:
// // bucket1->Empty
// // bucket2->Empty
// // bucket3->Empty


// // Test Case 4: Store string values
// {
//     HashMap<int, std::string> map(6);

//     map.set(1, "Apple");
//     map.set(2, "Banana");

//     std::cout << map.get(1) << std::endl;
//     std::cout << map.get(2) << std::endl;
// }
// // Expected:
// // Apple
// // Banana


// // Test Case 5: Check initial load factor
// {
//     HashMap<int, int> map(20);

//     std::cout << map.loadFactor() << std::endl;
// }
// // Expected:
// // 0
// // (or 0.0 depending on compiler)



// // =====================================================
// // ===== Method: Assignment Operator ===================
// // =====================================================

// // Test Case 1: Assign an empty HashMap
// {
//     HashMap<int, int> map1;
//     HashMap<int, int> map2;

//     map2 = map1;

//     std::cout << map2.getSize() << " "
//               << map2.getCapacity() << std::endl;
// }
// // Expected:
// // 0 8


// // Test Case 2: Assign a HashMap with one element
// {
//     HashMap<int, int> map1;
//     map1.set(10, 100);

//     HashMap<int, int> map2;
//     map2 = map1;

//     std::cout << map2.get(10) << std::endl;
//     std::cout << map2.getSize() << std::endl;
// }
// // Expected:
// // 100
// // 1


// // Test Case 3: Assign a HashMap with multiple elements
// {
//     HashMap<int, std::string> map1;

//     map1.set(1, "One");
//     map1.set(2, "Two");
//     map1.set(3, "Three");

//     HashMap<int, std::string> map2;
//     map2 = map1;

//     std::cout << map2.get(1) << std::endl;
//     std::cout << map2.get(2) << std::endl;
//     std::cout << map2.get(3) << std::endl;
// }
// // Expected:
// // One
// // Two
// // Three


// // Test Case 4: Verify deep copy
// {
//     HashMap<int, int> map1;

//     map1.set(1, 10);
//     map1.set(2, 20);

//     HashMap<int, int> map2;
//     map2 = map1;

//     map1.set(1, 999);

//     std::cout << map1.get(1) << std::endl;
//     std::cout << map2.get(1) << std::endl;
// }
// // Expected:
// // 999
// // 10


// // Test Case 5: Self assignment
// {
//     HashMap<int, int> map;

//     map.set(1, 100);
//     map.set(2, 200);

//     map = map;

//     std::cout << map.get(1) << std::endl;
//     std::cout << map.get(2) << std::endl;
//     std::cout << map.getSize() << std::endl;
// }
// // Expected:
// // 100
// // 200
// // 2



// // =====================================================
// // ===== Method: Destructor ============================
// // =====================================================

// // Test Case 1: Destroy an empty HashMap
// {
//     HashMap<int, int> map;
// }
// // Expected:
// // Object destroyed successfully.
// // No crash.
// // No memory leak.


// // Test Case 2: Destroy a HashMap with one element
// {
//     HashMap<int, int> map;

//     map.set(10, 100);
// }
// // Expected:
// // Object destroyed successfully.
// // No crash.
// // No memory leak.


// // Test Case 3: Destroy a HashMap with multiple elements
// {
//     HashMap<int, std::string> map;

//     map.set(1, "One");
//     map.set(2, "Two");
//     map.set(3, "Three");
// }
// // Expected:
// // All elements destroyed correctly.
// // No crash.
// // No memory leak.


// // Test Case 4: Destroy after reHash()
// {
//     HashMap<int, int> map;

//     for (int i = 1; i <= 20; i++)
//     {
//         map.set(i, i * 100);
//     }
// }
// // Expected:
// // Destructor runs successfully after rehash.
// // No double free.
// // No memory leak.


// // Test Case 5: Nested scope destruction
// {
//     HashMap<int, int> map1;

//     {
//         HashMap<int, int> map2;

//         map2.set(1, 100);
//         map2.set(2, 200);
//     }

//     map1.set(10, 500);
// }
// // Expected:
// // map2 destroyed when inner scope ends.
// // map1 destroyed when outer scope ends.
// // No crash.
// // No memory leak.



// =====================================================
// ===== Method: set() =================================
// =====================================================

// Test Case 1: Insert one key-value pair
{
    HashMap<int, int> map;

    map.set(10, 100);

    std::cout << map.get(10) << std::endl;
    std::cout << map.getSize() << std::endl;
}
// Expected:
// 100
// 1


// Test Case 2: Insert multiple key-value pairs
{
    HashMap<int, int> map;

    map.set(1, 10);
    map.set(2, 20);
    map.set(3, 30);

    std::cout << map.get(1) << std::endl;
    std::cout << map.get(2) << std::endl;
    std::cout << map.get(3) << std::endl;
    std::cout << map.getSize() << std::endl;
}
// Expected:
// 10
// 20
// 30
// 3


// Test Case 3: Insert duplicate key (should update value)
{
    HashMap<int, int> map;

    map.set(5, 50);
    map.set(5, 500);

    std::cout << map.get(5) << std::endl;
    std::cout << map.getSize() << std::endl;
}
// Expected:
// 500
// 1


// Test Case 4: Store string values
{
    HashMap<int, std::string> map;

    map.set(1, "Apple");
    map.set(2, "Banana");

    std::cout << map.get(1) << std::endl;
    std::cout << map.get(2) << std::endl;
}
// Expected:
// Apple
// Banana


// Test Case 5: Trigger reHash()
{
    HashMap<int, int> map;

    for (int i = 1; i <= 20; i++)
    {
        map.set(i, i * 100);
    }

    std::cout << map.getCapacity() << std::endl;
    std::cout << map.getSize() << std::endl;
    std::cout << map.get(20) << std::endl;
}
// Expected:
// 32
// 20
// 2000
  return 0;
}