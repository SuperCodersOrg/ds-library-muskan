#include <stdexcept>
template <typename K, typename V>
HashMap<K, V>::HashMap() : size(0), capacity(8), buckets(8)
{
  for (int i = 0; i < capacity; i++)
  {
    buckets.append(LinkList<Pair>());
  }
}
template <typename K, typename V>
HashMap<K, V>::HashMap(int capacity) : size(0), capacity(capacity), buckets(capacity)
{
  for (int i = 0; i < capacity; i++)
  {
    buckets.append(LinkList<Pair>());
  }
}
// HashMap::HashMap(HashMap &other){

// }
template <typename K, typename V>
void HashMap<K, V>::reHash()
{
  int newCapacity = 2 * capacity;
  // LinkList<Pair>* temp=(LinkList<Pair>*)malloc(sizeOf(LinkList<Pair>)*newCapacity);
  DynamicArray<LinkList<Pair>> newBuckets(newCapacity);
  for (int i = 0; i < newCapacity; i++)
  {
    newBuckets.append(LinkList<Pair>());
  }

  int i = 0;

  while (i < capacity)
  {
    LinkList<Pair> &oldBucketList = buckets.get(i);
    int j = 0;
    int listSize = oldBucketList.getSize();
    while (j < listSize)
    {
      HashMap::Pair p = oldBucketList.get(j);
      size_t newBucketNo = getHash(p.key) % newCapacity;
      LinkList<Pair> &newBucketList = newBuckets.get(newBucketNo);
      newBucketList.insertBack(p);
      // if(newBuckets.get(newBucketNo).isEmpty()){
      //   newBuckets.get(newBucketNo).insertBack(p);
      // }else{
      // int k=0;
      // LinkList<Pair> newBucketList=newBuckets.get(newBucketNo);
      // int newBucketListSize=newBucketList.getSize();

      // while(k<newBucketListSize){
      //   if(p.key==newBucketList.get(k).key){
      //     newBucketList.set(k,p);
      //     break;
      //   }
      //   ++k;
      // }
      // }
      ++j;
    }
    ++i;
  }
  // buckets.~DynamicArray();
  buckets = newBuckets;
  capacity = newCapacity;
}
template <typename K, typename V>
int HashMap<K, V>::getSize()
{
  return size;
}
template <typename K, typename V>
int HashMap<K, V>::getCapacity()
{
  return capacity;
}
template <typename K, typename V>
void HashMap<K, V>::set(const K &key, const V &value)
{
  Pair p(key, value);
  size_t bucketNo = getHash(key) % capacity;
  LinkList<Pair> &temp = buckets.get(bucketNo);
  // if(temp==nullptr){
  //   temp.insertFront(p);
  // }else{
  int size = temp.getSize();
  // std::cout<<"LIst"<<size<<"\n";
  int i = 0;
  while (i < size)
  {
    if (temp.get(i).key == key)
    {
      temp.set(i, p);
      return;
    }
    ++i;
  }
  temp.insertBack(p);
  ++this->size;
  //  std::cout<<"Hash"<<this->size<<"\n";
  // std::cout<<(float)size/capacity<<"hi\n";
  if ((float)this->size / capacity > 0.75)
    reHash();
}

template <typename K, typename V>
const V &HashMap<K, V>::get(const K &key)
{
  size_t bucketNo = getHash(key) % capacity;
  LinkList<Pair> &temp = buckets.get(bucketNo);
  int i = 0;
  // LinkList<Pair> *temporary=temp->head;
  while (i < temp.getSize())
  {
    if (temp.get(i).key == key)
    {
      return temp.get(i).value;
    }
    ++i;
  }
  throw std::invalid_argument("key doesnot exist");
}
template <typename K, typename V>
void HashMap<K, V>::print()
{
  for (int i = 0; i < capacity; i++)
  {
    LinkList<Pair> &temp = buckets.get(i);
    std::cout << "bucket" << i + 1 << "->";
    int j = 0;
    int size = temp.getSize();
    if (size == 0)
    {
      std::cout << "Empty";
    }
    else
      while (j < size)
      {
        if (j == size - 1)
          std::cout << "(" << temp.get(j).key << "," << temp.get(j).value << ")";
        else
          std::cout << "(" << temp.get(j).key << "," << temp.get(j).value << ")->";
        ++j;
      }
    // LinkList<Pair>::Node * move=temp.head;
    // while(move!=nullptr){
    //   if(move->next!=nullptr)
    //   std::cout<<move->data->value<<"->";
    //   move=move->next;
    // }
    std::cout << "\n";
  }
}
// HashMap::Pair* HashMap<Pair>::find(int key){
//   for(int i=0;i<this->buckets.getSize();i++){
//     LinkList<Pair>& list=.get(i);
//     int j=0;
//     while(j<list.getSize()){
//       HashMap::Pair& p=list.get(j);
//       if(p.key==key){
//         return &p;
//       }
//       ++j;
//     }
//   }
//   return nullptr;
// }
template <typename K, typename V>
void HashMap<K, V>::remove(const K &key)
{
  size_t bucketNo = getHash(key) % capacity;
  LinkList<Pair> &list = buckets.get(bucketNo);
  int size = list.getSize();
  int i = 0;
  while (i < size)
  {
    if (list.get(i).key == key)
    {
      list.removeAt(i);
      return;
    }
    ++i;
  }
  throw std::invalid_argument("key did not exist");
}
template <typename K, typename V>
bool HashMap<K, V>::exist(const K &key)
{
  size_t bucketNo = getHash(key) % capacity;
  LinkList<Pair> &list = buckets.get(bucketNo);
  int size = list.getSize();
  int i = 0;
  while (i < size)
  {
    if (list.get(i).key == key)
    {
      return true;
    }
    ++i;
  }
  return false;
}
template <typename K, typename V>
float HashMap<K,V>::loadFactor(){
 return (float)this->size/this->capacity;
}