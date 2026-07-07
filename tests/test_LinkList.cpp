#include<iostream>
#include<string>
#include <cassert>
#include "../include/LinkList/LinkList.h"
using namespace std;

int main()
{
    // // Test Case 1
    // {
    //     LinkList<int> l;

    //     cout << "===== Test Case 1 =====" << endl;
    //     cout << "Expected Size: 0" << endl;
    //     cout << "Actual Size:   " << l.getSize() << endl;

    //     cout << "Expected isEmpty: 1" << endl;
    //     cout << "Actual isEmpty:   " << l.isEmpty() << endl;
    //     cout << endl;
    // }

    // // Test Case 2
    // {
    //     LinkList<int> l1;
    //     LinkList<int> l2;

    //     l1.insertBack(100);

    //     cout << "===== Test Case 2 =====" << endl;
    //     cout << "Expected l1 Size: 1" << endl;
    //     cout << "Actual l1 Size:   " << l1.getSize() << endl;

    //     cout << "Expected l2 Size: 0" << endl;
    //     cout << "Actual l2 Size:   " << l2.getSize() << endl;
    //     cout << endl;
    // }

    // // Test Case 3
    // {
    //     LinkList<string> l;

    //     cout << "===== Test Case 3 =====" << endl;
    //     cout << "Expected Size: 0" << endl;
    //     cout << "Actual Size:   " << l.getSize() << endl;

    //     cout << "Expected isEmpty: 1" << endl;
    //     cout << "Actual isEmpty:   " << l.isEmpty() << endl;
    //     cout << endl;
    // }

    // // Test Case 4
    // {
    //     LinkList<int> l;

    //     l.insertFront(50);

    //     cout << "===== Test Case 4 =====" << endl;
    //     cout << "Expected Front: 50" << endl;
    //     cout << "Actual Front:   " << l.getFront() << endl;

    //     cout << "Expected Back: 50" << endl;
    //     cout << "Actual Back:   " << l.getBack() << endl;

    //     cout << "Expected Size: 1" << endl;
    //     cout << "Actual Size:   " << l.getSize() << endl;
    //     cout << endl;
    // }

    // // Test Case 5
    // {
    //     LinkList<int> l;

    //     cout << "===== Test Case 5 =====" << endl;
    //     cout << "Expected: Exception" << endl;
    //     cout << "Actual: ";

    //     try
    //     {
    //         cout << l.getFront() << endl;
    //     }
    //     catch (const exception& e)
    //     {
    //         cout << "Exception Thrown" << endl;
    //     }

    //     cout << endl;
    // }
    



    // =======================
// Destructor ~LinkList()
// =======================

// // Test Case 1: Destructor on empty list
// {
//     {
//         LinkList<int> list;
//     } // Destructor called here

//     std::cout << "Destructor Test 1 Passed\n";
// }
// // Test Case 2: Destructor on list with one element
// {
//     {
//         LinkList<int> list;
//         list.insertBack(10);
//     } // Destructor called here

//     std::cout << "Destructor Test 2 Passed\n";
// }
// // Test Case 3: Destructor on list with multiple elements
// {
//     {
//         LinkList<int> list;

//         for (int i = 1; i <= 100; i++)
//         {
//             list.insertBack(i);
//         }
//     } // Destructor called here

//     std::cout << "Destructor Test 3 Passed\n";
// }
// // Test Case 4: Destructor after multiple insert and delete operations
// {
//     {
//         LinkList<int> list;

//         for (int i = 1; i <= 20; i++)
//         {
//             list.insertBack(i);
//         }

//         list.deleteFront();
//         list.deleteFront();
//         list.deleteBack();
//         list.removeAt(5);
//         list.insertFront(100);
//         list.insertBack(200);
//     } // Destructor called here

//     std::cout << "Destructor Test 4 Passed\n";
// }
// // Test Case 5: Repeated construction and destruction
// {
//     for (int j = 0; j < 100; j++)
//     {
//         LinkList<int> list;

//         for (int i = 0; i < 50; i++)
//         {
//             list.insertBack(i);
//         }
//     } // Destructor called every iteration

//     std::cout << "Destructor Test 5 Passed\n";
// }



// ======================================
// Copy Constructor LinkList(const LinkList&)
// ======================================

// // Test Case 1: Copy an empty list
// {
//     LinkList<int> list1;
//     LinkList<int> list2(list1);

//     assert(list2.getSize() == 0);
//     assert(list2.isEmpty());

//     std::cout << "Copy Constructor Test 1 Passed\n";
// }
// // Test Case 2: Copy a list with one element
// {
//     LinkList<int> list1;
//     list1.insertBack(10);

//     LinkList<int> list2(list1);

//     assert(list2.getSize() == 1);
//     assert(list2.getFront() == 10);
//     assert(list2.getBack() == 10);

//     std::cout << "Copy Constructor Test 2 Passed\n";
// }
// // Test Case 3: Copy a list with multiple elements
// {
//     LinkList<int> list1;

//     for (int i = 1; i <= 5; i++)
//     {
//         list1.insertBack(i);
//     }

//     LinkList<int> list2(list1);

//     assert(list2.getSize() == 5);

//     for (int i = 0; i < 5; i++)
//     {
//         assert(list2.get(i) == i + 1);
//     }

//     std::cout << "Copy Constructor Test 3 Passed\n";
// }
// // Test Case 4: Verify deep copy
// {
//     LinkList<int> list1;

//     list1.insertBack(10);
//     list1.insertBack(20);
//     list1.insertBack(30);

//     LinkList<int> list2(list1);

//     list1.set(1, 99);

//     assert(list1.get(1) == 99);
//     assert(list2.get(1) == 20);

//     std::cout << "Copy Constructor Test 4 Passed\n";
// }
// // Test Case 5: Modify copied list only
// {
//     LinkList<int> list1;

//     list1.insertBack(1);
//     list1.insertBack(2);
//     list1.insertBack(3);

//     LinkList<int> list2(list1);

//     list2.insertBack(4);
//     list2.deleteFront();

//     assert(list1.getSize() == 3);
//     assert(list1.getFront() == 1);
//     assert(list1.getBack() == 3);

//     assert(list2.getSize() == 3);
//     assert(list2.getFront() == 2);
//     assert(list2.getBack() == 4);

//     std::cout << "Copy Constructor Test 5 Passed\n";
// }



// // Test Case 1: Assign empty list to empty list
// {
//     LinkList<int> list1;
//     LinkList<int> list2;

//     list2 = list1;

//     assert(list1.getSize() == 0);
//     assert(list2.getSize() == 0);
//     assert(list1.isEmpty());
//     assert(list2.isEmpty());

//     cout << "Assignment Operator Test 1 Passed\n";
// }

// // Test Case 2: Assign non-empty list to empty list
// {
//     LinkList<int> list1;
//     list1.insertBack(10);
//     list1.insertBack(20);
//     list1.insertBack(30);

//     LinkList<int> list2;

//     list2 = list1;

//     assert(list2.getSize() == 3);
//     assert(list2.getFront() == 10);
//     assert(list2.getBack() == 30);

//     for (int i = 0; i < 3; i++)
//     {
//         assert(list2.get(i) == list1.get(i));
//     }

//     cout << "Assignment Operator Test 2 Passed\n";
// }

// // Test Case 3: Assign over an existing list
// {
//     LinkList<int> list1;
//     list1.insertBack(1);
//     list1.insertBack(2);
//     list1.insertBack(3);

//     LinkList<int> list2;
//     list2.insertBack(100);
//     list2.insertBack(200);

//     list2 = list1;

//     assert(list2.getSize() == 3);

//     for (int i = 0; i < 3; i++)
//     {
//         assert(list2.get(i) == list1.get(i));
//     }

//     cout << "Assignment Operator Test 3 Passed\n";
// }

// // Test Case 4: Verify deep copy
// {
//     LinkList<int> list1;
//     list1.insertBack(5);
//     list1.insertBack(10);
//     list1.insertBack(15);

//     LinkList<int> list2;
//     list2 = list1;

//     list1.set(1, 99);

//     assert(list1.get(1) == 99);
//     assert(list2.get(1) == 10);

//     cout << "Assignment Operator Test 4 Passed\n";
// }

// // Test Case 5: Self assignment
// {
//     LinkList<int> list;

//     for (int i = 1; i <= 5; i++)
//     {
//         list.insertBack(i);
//     }

//     list = list;

//     assert(list.getSize() == 5);

//     for (int i = 0; i < 5; i++)
//     {
//         assert(list.get(i) == i + 1);
//     }

//     cout << "Assignment Operator Test 5 Passed\n";
// }



// //insert method tested
// // Test Case 1: Insert at front of an empty list
// {
//     LinkList<int> list;

//     list.insertFront(10);

//     assert(list.getSize() == 1);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 10);

//     cout << "insertFront Test 1 Passed\n";
// }

// // Test Case 2: Insert multiple elements at front
// {
//     LinkList<int> list;

//     list.insertFront(10);
//     list.insertFront(20);
//     list.insertFront(30);

//     assert(list.getSize() == 3);
//     assert(list.getFront() == 30);
//     assert(list.getBack() == 10);

//     assert(list.get(0) == 30);
//     assert(list.get(1) == 20);
//     assert(list.get(2) == 10);

//     cout << "insertFront Test 2 Passed\n";
// }

// // Test Case 3: Insert negative values at front
// {
//     LinkList<int> list;

//     list.insertFront(-5);
//     list.insertFront(-10);

//     assert(list.getSize() == 2);
//     assert(list.getFront() == -10);
//     assert(list.getBack() == -5);

//     cout << "insertFront Test 3 Passed\n";
// }

// // Test Case 4: Insert strings at front
// {
//     LinkList<string> list;

//     list.insertFront("World");
//     list.insertFront("Hello");

//     assert(list.getSize() == 2);
//     assert(list.getFront() == "Hello");
//     assert(list.getBack() == "World");

//     cout << "insertFront Test 4 Passed\n";
// }

// // Test Case 5: Large number of insertFront operations
// {
//     LinkList<int> list;

//     for(int i = 1; i <= 100; i++)
//     {
//         list.insertFront(i);
//     }

//     assert(list.getSize() == 100);
//     assert(list.getFront() == 100);
//     assert(list.getBack() == 1);

//     cout << "insertFront Test 5 Passed\n";
// }



// ===============================
// Method: insertBack()
// ===============================

// // Test Case 1: Insert into an empty list
// {
//     LinkList<int> list;

//     list.insertBack(10);

//     assert(list.getSize() == 1);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 10);

//     cout << "insertBack Test 1 Passed\n";
// }

// // Test Case 2: Insert multiple elements at back
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     assert(list.getSize() == 3);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 30);

//     assert(list.get(0) == 10);
//     assert(list.get(1) == 20);
//     assert(list.get(2) == 30);

//     cout << "insertBack Test 2 Passed\n";
// }

// // Test Case 3: Insert negative values
// {
//     LinkList<int> list;

//     list.insertBack(-10);
//     list.insertBack(-20);

//     assert(list.getSize() == 2);
//     assert(list.getFront() == -10);
//     assert(list.getBack() == -20);

//     cout << "insertBack Test 3 Passed\n";
// }

// // Test Case 4: Insert string values
// {
//     LinkList<string> list;

//     list.insertBack("Hello");
//     list.insertBack("World");

//     assert(list.getSize() == 2);
//     assert(list.getFront() == "Hello");
//     assert(list.getBack() == "World");

//     cout << "insertBack Test 4 Passed\n";
// }

// // Test Case 5: Large number of insertions
// {
//     LinkList<int> list;

//     for (int i = 1; i <= 100; i++)
//     {
//         list.insertBack(i);
//     }

//     assert(list.getSize() == 100);
//     assert(list.getFront() == 1);
//     assert(list.getBack() == 100);

//     cout << "insertBack Test 5 Passed\n";
// }



// ===============================
// Method: insert(int index, const T& value)
// ===============================

// // Test Case 1: Insert at the beginning
// {
//     LinkList<int> list;

//     list.insertBack(20);
//     list.insertBack(30);
//     list.insert(0, 10);

//     assert(list.getSize() == 3);
//     assert(list.get(0) == 10);
//     assert(list.get(1) == 20);
//     assert(list.get(2) == 30);

//     cout << "insert() Test 1 Passed\n";
// }

// // Test Case 2: Insert in the middle
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(30);
//     list.insert(1, 20);

//     assert(list.getSize() == 3);
//     assert(list.get(0) == 10);
//     assert(list.get(1) == 20);
//     assert(list.get(2) == 30);

//     cout << "insert() Test 2 Passed\n";
// }

// // Test Case 3: Insert at the end
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insert(2, 30);

//     assert(list.getSize() == 3);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 30);

//     cout << "insert() Test 3 Passed\n";
// }

// // Test Case 4: Invalid negative index
// {
//     LinkList<int> list;

//     try
//     {
//         list.insert(-1, 100);
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "insert() Test 4 Passed\n";
//     }
// }

// // Test Case 5: Index greater than size
// {
//     LinkList<int> list;

//     list.insertBack(10);

//     try
//     {
//         list.insert(2, 20);
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "insert() Test 5 Passed\n";
//     }
// }



// ===============================
// Method: deleteFront()
// ===============================

// // Test Case 1: Delete from an empty list
// {
//     LinkList<int> list;

//     list.deleteFront();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteFront() Test 1 Passed\n";
// }

// // Test Case 2: Delete the only element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.deleteFront();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteFront() Test 2 Passed\n";
// }

// // Test Case 3: Delete front from a multi-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.deleteFront();

//     assert(list.getSize() == 2);
//     assert(list.getFront() == 20);
//     assert(list.getBack() == 30);

//     cout << "deleteFront() Test 3 Passed\n";
// }

// // Test Case 4: Delete front multiple times
// {
//     LinkList<int> list;

//     for (int i = 1; i <= 5; i++)
//     {
//         list.insertBack(i);
//     }

//     list.deleteFront();
//     list.deleteFront();

//     assert(list.getSize() == 3);
//     assert(list.getFront() == 3);
//     assert(list.getBack() == 5);

//     cout << "deleteFront() Test 4 Passed\n";
// }

// // Test Case 5: Delete until the list becomes empty
// {
//     LinkList<int> list;

//     list.insertBack(1);
//     list.insertBack(2);
//     list.insertBack(3);

//     list.deleteFront();
//     list.deleteFront();
//     list.deleteFront();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteFront() Test 5 Passed\n";
// }



// ===============================
// Method: deleteBack()
// ===============================

// Test Case 1: Delete from an empty list
// {
//     LinkList<int> list;

//     list.deleteBack();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteBack() Test 1 Passed\n";
// }

// // Test Case 2: Delete the only element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.deleteBack();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteBack() Test 2 Passed\n";
// }

// // Test Case 3: Delete back from a multi-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.deleteBack();

//     assert(list.getSize() == 2);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 20);

//     cout << "deleteBack() Test 3 Passed\n";
// }

// // Test Case 4: Delete back multiple times
// {
//     LinkList<int> list;

//     for (int i = 1; i <= 5; i++)
//     {
//         list.insertBack(i);
//     }

//     list.deleteBack();
//     list.deleteBack();

//     assert(list.getSize() == 3);
//     assert(list.getFront() == 1);
//     assert(list.getBack() == 3);

//     cout << "deleteBack() Test 4 Passed\n";
// }

// // Test Case 5: Delete until the list becomes empty
// {
//     LinkList<int> list;

//     list.insertBack(1);
//     list.insertBack(2);
//     list.insertBack(3);

//     list.deleteBack();
//     list.deleteBack();
//     list.deleteBack();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "deleteBack() Test 5 Passed\n";
// }



// // ===============================
// // Method: removeAt(int index)
// // ===============================

// // Test Case 1: Remove first element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.removeAt(0);

//     assert(list.getSize() == 2);
//     assert(list.getFront() == 20);
//     assert(list.getBack() == 30);

//     cout << "removeAt() Test 1 Passed\n";
// }

// // Test Case 2: Remove middle element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);
//     list.insertBack(40);

//     list.removeAt(2);

//     assert(list.getSize() == 3);
//     assert(list.get(0) == 10);
//     assert(list.get(1) == 20);
//     assert(list.get(2) == 40);

//     cout << "removeAt() Test 2 Passed\n";
// }

// // Test Case 3: Remove last element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.removeAt(2);

//     assert(list.getSize() == 2);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 20);

//     cout << "removeAt() Test 3 Passed\n";
// }

// // Test Case 4: Remove with negative index
// {
//     LinkList<int> list;

//     list.insertBack(10);

//     try
//     {
//         list.removeAt(-1);
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "removeAt() Test 4 Passed\n";
//     }
// }

// // Test Case 5: Remove with index >= size
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);

//     try
//     {
//         list.removeAt(2);
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "removeAt() Test 5 Passed\n";
//     }
// }



// ===============================
// Method: removeValue(const T& value)
// ===============================

// // Test Case 1: Remove value from the front
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     bool result = list.removeValue(10);

//     assert(result == true);
//     assert(list.getSize() == 2);
//     assert(list.getFront() == 20);
//     assert(list.getBack() == 30);

//     cout << "removeValue() Test 1 Passed\n";
// }

// // Test Case 2: Remove value from the middle
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     bool result = list.removeValue(20);

//     assert(result == true);
//     assert(list.getSize() == 2);
//     assert(list.get(0) == 10);
//     assert(list.get(1) == 30);

//     cout << "removeValue() Test 2 Passed\n";
// }

// // Test Case 3: Remove value from the back
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     bool result = list.removeValue(30);

//     assert(result == true);
//     assert(list.getSize() == 2);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 20);

//     cout << "removeValue() Test 3 Passed\n";
// }

// // Test Case 4: Remove value that does not exist
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);

//     bool result = list.removeValue(50);

//     assert(result == false);
//     assert(list.getSize() == 2);
//     assert(list.getFront() == 10);
//     assert(list.getBack() == 20);

//     cout << "removeValue() Test 4 Passed\n";
// }

// // Test Case 5: Remove from an empty list
// {
//     LinkList<int> list;

//     bool result = list.removeValue(10);

//     assert(result == false);
//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "removeValue() Test 5 Passed\n";
// }



// ===============================
// Method: clear()
// ===============================

// // Test Case 1: Clear an empty list
// {
//     LinkList<int> list;

//     list.clear();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "clear() Test 1 Passed\n";
// }

// // Test Case 2: Clear a list with one element
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.clear();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "clear() Test 2 Passed\n";
// }

// // Test Case 3: Clear a list with multiple elements
// {
//     LinkList<int> list;

//     for (int i = 1; i <= 5; i++)
//     {
//         list.insertBack(i);
//     }

//     list.clear();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "clear() Test 3 Passed\n";
// }

// // Test Case 4: Insert again after clear
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);

//     list.clear();

//     list.insertBack(30);

//     assert(list.getSize() == 1);
//     assert(list.getFront() == 30);
//     assert(list.getBack() == 30);

//     cout << "clear() Test 4 Passed\n";
// }

// // Test Case 5: Clear twice
// {
//     LinkList<int> list;

//     list.insertBack(1);
//     list.insertBack(2);
//     list.insertBack(3);

//     list.clear();
//     list.clear();

//     assert(list.getSize() == 0);
//     assert(list.isEmpty());

//     cout << "clear() Test 5 Passed\n";
// }



// ===============================
// Method: getFront() const
// ===============================

// Test Case 1: Get front from a single-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);

//     assert(list.getFront() == 10);
//     assert(list.getSize() == 1);

//     cout << "getFront() Test 1 Passed\n";
// }

// // Test Case 2: Get front from a multi-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     assert(list.getFront() == 10);

//     cout << "getFront() Test 2 Passed\n";
// }

// // Test Case 3: Front should update after deleteFront()
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.deleteFront();

//     assert(list.getFront() == 20);

//     cout << "getFront() Test 3 Passed\n";
// }

// // Test Case 4: Front should update after insertFront()
// {
//     LinkList<int> list;

//     list.insertBack(20);
//     list.insertBack(30);

//     list.insertFront(10);

//     assert(list.getFront() == 10);

//     cout << "getFront() Test 4 Passed\n";
// }

// // Test Case 5: Calling getFront() on an empty list should throw
// {
//     LinkList<int> list;

//     try
//     {
//         list.getFront();
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "getFront() Test 5 Passed\n";
//     }
// }



// ===============================
// Method: getBack() const
// ===============================

// // Test Case 1: Get back from a single-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);

//     assert(list.getBack() == 10);
//     assert(list.getSize() == 1);

//     cout << "getBack() Test 1 Passed\n";
// }

// // Test Case 2: Get back from a multi-element list
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     assert(list.getBack() == 30);

//     cout << "getBack() Test 2 Passed\n";
// }

// // Test Case 3: Back should update after deleteBack()
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);
//     list.insertBack(30);

//     list.deleteBack();

//     assert(list.getBack() == 20);

//     cout << "getBack() Test 3 Passed\n";
// }

// // Test Case 4: Back should update after insertBack()
// {
//     LinkList<int> list;

//     list.insertBack(10);
//     list.insertBack(20);

//     list.insertBack(30);

//     assert(list.getBack() == 30);

//     cout << "getBack() Test 4 Passed\n";
// }

// // Test Case 5: Calling getBack() on an empty list should throw
// {
//     LinkList<int> list;

//     try
//     {
//         list.getBack();
//         assert(false);
//     }
//     catch (const out_of_range&)
//     {
//         cout << "getBack() Test 5 Passed\n";
//     }
// }



// ===============================
// Method: get(int index) const
// ===============================

// Test Case 1: Get first element using index 0
{
    LinkList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    assert(list.get(0) == 10);

    cout << "get() Test 1 Passed\n";
}

// Test Case 2: Get middle element
{
    LinkList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    assert(list.get(1) == 20);

    cout << "get() Test 2 Passed\n";
}

// Test Case 3: Get last element
{
    LinkList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    assert(list.get(2) == 30);

    cout << "get() Test 3 Passed\n";
}

// Test Case 4: Invalid negative index should throw
{
    LinkList<int> list;

    list.insertBack(10);

    try
    {
        list.get(-1);
        assert(false);
    }
    catch (const out_of_range&)
    {
        cout << "get() Test 4 Passed\n";
    }
}

// Test Case 5: Index greater than or equal to size should throw
{
    LinkList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    try
    {
        list.get(2);
        assert(false);
    }
    catch (const out_of_range&)
    {
        cout << "get() Test 5 Passed\n";
    }
}
    return 0;
}