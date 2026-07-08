#include<string>
#include<iostream>
#include "../DynamicArray/DynamicArray.h"
#include "../LinkList/LinkList.h"
#ifndef HASHMAP_H
#define HASHMAP_H
class HashMap{
  private:
    int size;
    int capacity;
    struct Pair{
      int key;
      std::string value;
      Pair():key(0),value(""){};
      Pair(int key,std::string value):key(key),value(value){};
    };
    DynamicArray<LinkList<Pair>> buckets;
    
    public:
    HashMap();
    // HashMap(HashMap& other);
    HashMap(int capacity);
    void reHash();
    int getSize();
    int getCapacity();
    void set(int key,std::string value);
    std::string get(int key);
    // Pair* find(int key);
    void remove(int key);
    void print();
    bool exist(int key);
};


#endif