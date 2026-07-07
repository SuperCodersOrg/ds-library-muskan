#include<string>
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
    HashMap(int capacity);
    void set(int key,std::string value);
    std::string get(int key);
};
#endif