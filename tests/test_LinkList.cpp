#include<iostream>
#include<string>
#include "../include/LinkList/LinkList.h"
using namespace std;

int main()
{
    // Test Case 1
    {
        LinkList<int> l;

        cout << "===== Test Case 1 =====" << endl;
        cout << "Expected Size: 0" << endl;
        cout << "Actual Size:   " << l.getSize() << endl;

        cout << "Expected isEmpty: 1" << endl;
        cout << "Actual isEmpty:   " << l.isEmpty() << endl;
        cout << endl;
    }

    // Test Case 2
    {
        LinkList<int> l1;
        LinkList<int> l2;

        l1.insertBack(100);

        cout << "===== Test Case 2 =====" << endl;
        cout << "Expected l1 Size: 1" << endl;
        cout << "Actual l1 Size:   " << l1.getSize() << endl;

        cout << "Expected l2 Size: 0" << endl;
        cout << "Actual l2 Size:   " << l2.getSize() << endl;
        cout << endl;
    }

    // Test Case 3
    {
        LinkList<string> l;

        cout << "===== Test Case 3 =====" << endl;
        cout << "Expected Size: 0" << endl;
        cout << "Actual Size:   " << l.getSize() << endl;

        cout << "Expected isEmpty: 1" << endl;
        cout << "Actual isEmpty:   " << l.isEmpty() << endl;
        cout << endl;
    }

    // Test Case 4
    {
        LinkList<int> l;

        l.insertFront(50);

        cout << "===== Test Case 4 =====" << endl;
        cout << "Expected Front: 50" << endl;
        cout << "Actual Front:   " << l.getFront() << endl;

        cout << "Expected Back: 50" << endl;
        cout << "Actual Back:   " << l.getBack() << endl;

        cout << "Expected Size: 1" << endl;
        cout << "Actual Size:   " << l.getSize() << endl;
        cout << endl;
    }

    // Test Case 5
    {
        LinkList<int> l;

        cout << "===== Test Case 5 =====" << endl;
        cout << "Expected: Exception" << endl;
        cout << "Actual: ";

        try
        {
            cout << l.getFront() << endl;
        }
        catch (const exception& e)
        {
            cout << "Exception Thrown" << endl;
        }

        cout << endl;
    }

    return 0;
}