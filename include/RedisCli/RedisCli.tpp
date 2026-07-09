#include <iostream>
#include <stdexcept>
#include <string>
#include<sstream>
template <typename K, typename V>
void RedisCli<K, V>::handleSet(const K &key, const V &value)
{
  store.set(key, value);
  std::cout << "OK" << std::endl;
}
template <typename K, typename V>
void RedisCli<K, V>::handleGet(const K &key)
{
  try
  {
    std::cout << store.get(key) << std::endl;
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
}
template <typename K, typename V>
void RedisCli<K, V>::handleClear()
{
  store.clear();
  std::cout << "OK" << std::endl;
}
template <typename K, typename V>
void RedisCli<K, V>::handleCount()
{
  std::cout << store.getSize() << std::endl;
}
template <typename K, typename V>
void RedisCli<K, V>::handlePrint()
{
  store.print();
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
template <typename K, typename V>
void RedisCli<K, V>::run()
{
  std::cout << "REDIS:\n";
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
    else
    {
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
