#ifndef REDISCLI_H
#define REDISCLI_H
#include "../HashMap/HashMap.h"
#include<string>
template<typename K,typename V>
class RedisCli{
  private:
    HashMap<K,V> store;
    void handleSet(const K& key,const V& value);
    void handleGet(const K& key);
    void handleDel(const K& key);
    void handleExists(const K& key);
    void handleClear();
    void handleCount();
    void handlePrint();
    void toUpperCase(std::string& str);
  public:
    void run();

};
#include "./RedisCli.tpp"
#endif 