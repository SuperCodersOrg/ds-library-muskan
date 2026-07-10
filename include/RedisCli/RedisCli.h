#ifndef REDISCLI_H
#define REDISCLI_H
#include "../HashMap/HashMap.h"
#include<string>
template<typename K,typename V>
class RedisCli{
  private:
    HashMap<K,V> store;
    private:
    int setCount = 0;
    int getCount = 0;
    int delCount = 0;
    int existsCount = 0;
    int clearCount = 0;
    int countCount = 0;
    int printCount = 0;
    int helpCount = 0;
    int statsCount = 0;
    int invalidCommandCount = 0;
    void handleSet(const K& key,const V& value);
    void handleGet(const K& key);
    void handleDel(const K& key);
    void handleExists(const K& key);
    void handleClear();
    void handleCount();
    void handlePrint();
    void toUpperCase(std::string& str);
    void printWelcome();
    void printHelp();
    void printStats();
   
  public:
    void run();
    
};
#include "./RedisCli.tpp"
#endif 