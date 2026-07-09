#include<iostream>
#include<string>
#include "../include/HashMap/HashMap.h"
using namespace std;
int main(){
  // =====================================================
// ===== Method: Default Constructor ===================
// =====================================================

// Test Case 1: Create an empty HashMap
{
    HashMap<int, int> map;

    std::cout << map.getSize() << " "
              << map.getCapacity() << std::endl;
}
// Expected:
// 0 8


// Test Case 2: Two objects should be independent
{
    HashMap<int, int> map1;
    HashMap<int, int> map2;

    map1.set(10, 100);

    std::cout << map1.getSize() << " "
              << map2.getSize() << std::endl;
}
// Expected:
// 1 0


// Test Case 3: Verify initial load factor
{
    HashMap<int, int> map;

    std::cout << map.loadFactor() << std::endl;
}
// Expected:
// 0
// (or 0.0 depending on compiler)


//Test Case 4: Insert immediately after construction
{
    HashMap<int, std::string> map;

    map.set(1, "One");

    std::cout << map.get(1) << std::endl;
}
// Expected:
// One


// Test Case 5: Default constructor should create 8 buckets
{
    HashMap<int, int> map;

    map.print();
}
// Expected:
// bucket1->Empty
// bucket2->Empty
// bucket3->Empty
// bucket4->Empty
// bucket5->Empty
// bucket6->Empty
// bucket7->Empty
// bucket8->Empty

  return 0;
}