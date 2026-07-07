#include<iostream>
#include<string>
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

// Test Case 1: Destructor on empty list
{
    {
        LinkList<int> list;
    } // Destructor called here

    std::cout << "Destructor Test 1 Passed\n";
}
// Test Case 2: Destructor on list with one element
{
    {
        LinkList<int> list;
        list.insertBack(10);
    } // Destructor called here

    std::cout << "Destructor Test 2 Passed\n";
}
// Test Case 3: Destructor on list with multiple elements
{
    {
        LinkList<int> list;

        for (int i = 1; i <= 100; i++)
        {
            list.insertBack(i);
        }
    } // Destructor called here

    std::cout << "Destructor Test 3 Passed\n";
}
// Test Case 4: Destructor after multiple insert and delete operations
{
    {
        LinkList<int> list;

        for (int i = 1; i <= 20; i++)
        {
            list.insertBack(i);
        }

        list.deleteFront();
        list.deleteFront();
        list.deleteBack();
        list.removeAt(5);
        list.insertFront(100);
        list.insertBack(200);
    } // Destructor called here

    std::cout << "Destructor Test 4 Passed\n";
}
// Test Case 5: Repeated construction and destruction
{
    for (int j = 0; j < 100; j++)
    {
        LinkList<int> list;

        for (int i = 0; i < 50; i++)
        {
            list.insertBack(i);
        }
    } // Destructor called every iteration

    std::cout << "Destructor Test 5 Passed\n";
}
    return 0;
}