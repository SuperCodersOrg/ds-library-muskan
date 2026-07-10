#include <iostream>
#include <stdexcept>
#include <string>
#include<sstream>
template <typename K, typename V>
void RedisCli<K, V>::handleSet(const K &key, const V &value)
{
  store.set(key, value);
  ++setCount;
  std::cout << "OK" << std::endl;
}
template <typename K, typename V>
void RedisCli<K, V>::handleGet(const K &key)
{
  try
  {
    std::cout << store.get(key) << std::endl;
    ++getCount;
  }
  catch (const std::invalid_argument &)
  {
    std::cout << "Key Not Found" << std::endl;
  }
}

template <typename K, typename V>
void RedisCli<K, V>::handleDel(const K &key)
{
  try
  {
    store.remove(key);
    std::cout << "OK" << std::endl;
    ++delCount;
  }
  catch (const std::invalid_argument &)
  {
    std::cout << "Key Not Found" << std::endl;
  }
}
template <typename K, typename V>
void RedisCli<K, V>::handleExists(const K &key)
{

  std::cout << store.exist(key) << std::endl;
  ++existsCount;
}
template <typename K, typename V>
void RedisCli<K, V>::handleClear()
{
  store.clear();
  std::cout << "OK" << std::endl;
  ++clearCount;
}
template <typename K, typename V>
void RedisCli<K, V>::handleCount()
{ 
  
  std::cout << store.getSize() << std::endl;
  ++countCount;
}
template <typename K, typename V>
void RedisCli<K, V>::handlePrint()
{
  store.print();
  ++printCount;
}
template<typename T> 
T converter(const std::string& str){
  std::stringstream ss(str);
  T value{};
  if (!(ss >> value))
    throw std::invalid_argument("Invalid conversion");
  return value;
}
template<>
std::string converter<std::string>(const std::string& str)
{
    return str;
}
// template<typename K,typename V>
// void RedisCli<K,V>::rehashCount(){
//   return store.getRehashCount();
// }
template <typename K, typename V>
void RedisCli<K, V>::run()
{
  std::cout << "REDIS:\n";
  printWelcome();
  while (true)
  {
    std::string command;
    std::string method;
    std::string tempkey;
    std::string tempvalue;
    K key;
    V value;
    if (!std::getline(std::cin, command))
    break;
    if(command.empty())continue;
    int i = 0;
    int no = 0;
    int size=command.size();
    while (i<size)
    {
      if (command[i] == ' '&&no<2)
      {
        while(command[i+1]==' '&&i+1<size){
          ++i;
        }
        ++no;
      }
      else if (no == 0)
      {
        method.push_back(command[i]);
      }
      else if (no == 1)
      {

        tempkey.push_back(command[i]);
      }
      else
      { 
        tempvalue.push_back(command[i]);
      }
      ++i;
    }
    try{
    if(tempkey.size())
    key=converter<K>(tempkey);
    if(tempvalue.size())
    value=converter<V>(tempvalue);
    }catch(std::invalid_argument&){
      std::cout<<"Invalie key or value type\n";
      continue;
    }
    toUpperCase(method);
    // std::cout<<method;
    if (method == "SET")
    {
      // K key;
      // V value;
      // std::cin >> key;
      // std::cin >> value;
      if(tempkey.size()==0||tempvalue.size()==0){
        std::cout<<"Key and value both required\n";
        continue;
      }
      handleSet(key, value);
    }
    else if (method == "GET")
    {
      // K key;
      // std::cin >> key;
      if(tempkey.size()==0){
        std::cout<<"Key required\n";
        continue;
      }
      if(tempvalue.size()!=0){
        std::cout<<"value not required\n";
        continue;
      }
       handleGet(key);
    }
    else if (method == "DEL")
    {
      if(tempkey.size()==0){
        std::cout<<"Key required\n";
        continue;
      }
            if(tempvalue.size()!=0){
        std::cout<<"value not required\n";
        continue;
      }
      // K key;
      // std::cin >> key;
      handleDel(key);
    }
    else if (method == "EXISTS")
    {
            if(tempkey.size()==0){
        std::cout<<"Key required\n";
        continue;
      }
      if(tempvalue.size()!=0){
        std::cout<<"value not required\n";
        continue;
      }
      // K key;
      // std::cin >> key;
      handleExists(key);
    }
    else if (method == "CLEAR")
    {
      handleClear();
    }
    else if (method == "COUNT")
    {
      handleCount();
    }
    else if (method == "PRINT")
    {
      handlePrint();
    }
    else if (method == "EXIT")
    {
      break;
    }
    else if (method == "HELP")
    {
      printHelp();
    }
    else if (method == "STAT")
    {
      printStats();
    }
    else
    {
      ++invalidCommandCount;
      std::cout << "Invalid Command" << std::endl;
    }
  }
}

template <typename K, typename V>
void RedisCli<K, V>::toUpperCase(std::string &str)
{
  int i = 0;
  while (i<str.size())
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - ('a'-'A');
    i++;
  }
}

 
template<typename K, typename V>
void RedisCli<K, V>::printWelcome()
{
    std::cout << "=============================================================\n";
    std::cout << "                    REDIS LITE v1.0\n";
    std::cout << "=============================================================\n";
    std::cout << "A lightweight Redis implementation in C++\n\n";

    std::cout << "Storage Engine : HashMap (Separate Chaining)\n";
    std::cout << "Hash Function  : MurmurHash3\n";
    std::cout << "Initial Capacity : " << store.getCapacity() << "\n";
    std::cout << "Load Factor Threshold : 0.75\n";
    std::cout << "Persistence : No\n";
    std::cout << "Networking  : No\n\n";

    std::cout << "Type HELP to view all commands.\n";
    std::cout << "Type EXIT to quit Redis Lite.\n";

    std::cout << "=============================================================\n\n";
}

template<typename K, typename V>
void RedisCli<K, V>::printHelp()
{   ++helpCount;
    std::cout << "\n";
    std::cout << "==================== AVAILABLE COMMANDS ====================\n";
    std::cout << "| Command                  | Description                  |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "| SET <key> <value>        | Insert or update a value     |\n";
    std::cout << "| GET <key>                | Retrieve a value            |\n";
    std::cout << "| DEL <key>                | Delete a key                |\n";
    std::cout << "| EXISTS <key>             | Check if key exists         |\n";
    std::cout << "| COUNT                    | Number of stored keys       |\n";
    std::cout << "| CLEAR                    | Remove all key-value pairs  |\n";
    std::cout << "| PRINT                    | Display all buckets         |\n";
    std::cout << "| STATS                    | Display HashMap statistics  |\n";
    std::cout << "| HELP                     | Show this help menu         |\n";
    std::cout << "| EXIT                     | Exit Redis Lite             |\n";
    std::cout << "============================================================\n\n";
}
template<typename K,typename V>
void RedisCli<K,V>::printStats()
{
    ++statsCount;
    std::cout<<"\n";
    std::cout<<"==============================================================\n";
    std::cout<<"                    REDIS LITE STATISTICS\n";
    std::cout<<"==============================================================\n\n";

    std::cout<<"==================== HASHMAP STATS ====================\n\n";

    std::cout<<"Current Size            : "<<store.getSize()<<"\n";
    std::cout<<"Current Capacity        : "<<store.getCapacity()<<"\n";
    std::cout<<"Load Factor             : "<<store.loadFactor()<<"\n";
    std::cout<<"\n";

    std::cout<<"Hash Function           : MurmurHash3\n";
    std::cout<<"Collision Strategy      : Separate Chaining\n";
    std::cout<<"Bucket Structure        : Singly Linked List\n";
    std::cout<<"Resize Threshold        : 0.75\n";
    std::cout<<"Growth Strategy         : Capacity x2\n";

    std::cout<<"Empty Buckets           : "<<store.getEmptyBuckets()<<"\n";
    std::cout<<"Longest Chain           : "<<store.getLongestChain()<<"\n";
    std::cout<<"Total Collisions        : "<<store.getCollisionCount()<<"\n";
    std::cout<<"Number of Rehashes      : "<<store.getRehashCount()<<"\n";

    std::cout<<"\n";

    std::cout<<"=================== COMMAND STATS =====================\n\n";

    std::cout<<"SET Commands            : "<<setCount<<"\n";
    std::cout<<"GET Commands            : "<<getCount<<"\n";
    std::cout<<"DEL Commands            : "<<delCount<<"\n";
    std::cout<<"EXISTS Commands         : "<<existsCount<<"\n";
    std::cout<<"COUNT Commands          : "<<countCount<<"\n";
    std::cout<<"CLEAR Commands          : "<<clearCount<<"\n";
    std::cout<<"PRINT Commands          : "<<printCount<<"\n";
    std::cout<<"HELP Commands           : "<<helpCount<<"\n";
    std::cout<<"STATS Commands          : "<<statsCount<<"\n";
    std::cout<<"Invalid Commands        : "<<invalidCommandCount<<"\n";

    std::cout<<"\n";

    std::cout<<"=================== TIME COMPLEXITIES ==================\n\n";

    std::cout<<"SET      : O(1) Average | O(n) Worst\n";
    std::cout<<"GET      : O(1) Average | O(n) Worst\n";
    std::cout<<"DEL      : O(1) Average | O(n) Worst\n";
    std::cout<<"EXISTS   : O(1) Average | O(n) Worst\n";
    std::cout<<"COUNT    : O(1)\n";
    std::cout<<"CLEAR    : O(n)\n";
    std::cout<<"PRINT    : O(n)\n";

    std::cout<<"\n==============================================================\n";
}