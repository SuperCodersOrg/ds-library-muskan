#include<string>
#include<iostream>
#include "../DynamicArray/DynamicArray.h"
#include "../LinkList/LinkList.h"
#include "./MurmurHash3.h"
#ifndef HASHMAP_H
#define HASHMAP_H
template<typename K,typename V>
class HashMap{
  private:
    int size;
    int capacity;
    int rehashCount;
    int collisionCount;
    struct Pair{
      K key;
      V value;
      Pair():key(),value(){};
      Pair(K key,V value):key(key),value(value){};
    };
    DynamicArray<LinkList<Pair>> buckets;
    
    public:
   static int validate(int capacity)
{
    if (capacity <= 0)
        throw std::invalid_argument("Invalid capacity");
    return capacity;
}
    HashMap();
    // HashMap(HashMap& other);
    HashMap(int capacity);
    void reHash();
    int getSize();
    int getCapacity();
    void set(const K& key,const V& value);
    const V& get(const K& key);
    // Pair* find(int key);
    void remove(const K& key);
    void print();
    bool exist(const K& key);
    float loadFactor();
    void clear();
    int getRehashCount();
    int getCollisionCount();
    int getLongestChain();
    int getEmptyBuckets();
};

#include "./HashMap.tpp"
#endif