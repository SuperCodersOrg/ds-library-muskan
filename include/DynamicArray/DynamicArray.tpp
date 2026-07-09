#include <new>       //for bad_alloc exception
#include <stdexcept> //for logical error like invalid argument
#include <cstdlib>   //for malloc realloc
template <typename T>
DynamicArray<T>::DynamicArray()
{
  this->size = 0;
  this->capacity = 0;
  this->arr = nullptr;
}
template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
  if (capacity <= 0)
  {
    throw std::invalid_argument("Invalid argument");
  }
  this->size = 0;
  this->capacity = capacity;
  this->arr = (T *)malloc(sizeof(T) * this->capacity);
  if (this->arr == nullptr)
  {
    throw std::bad_alloc();
  }
}
template<typename T>
DynamicArray<T>::~DynamicArray(){
  // std::cout<<"deconstructor got called";
  for(int i=0;i<this->size;i++){
    this->arr[i].~T();
  }
  free(this->arr);
  // this->arr=nullptr;
}
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other){
  // std::cout<<"Dynamei array copy constructtor run";
  this->size=other.size;
  this->capacity=other.capacity;
  if(this->capacity==0){
    this->arr=nullptr;
    return;
  }
  T* temp=(T*)malloc(sizeof(T)*this->capacity);
  if(temp==nullptr){
    throw std::bad_alloc();
  }
  this->arr=temp;
  for(int i=0;i<this->size;i++){
    new(&this->arr[i])T(other.arr[i]);
  }
}

template<typename T>
int DynamicArray<T>::getSize() const{
  return this->size;
}
template<typename T>
int DynamicArray<T>::getCapacity() const{
  return this->capacity;
}
template <typename T>
void DynamicArray<T>::regrow()
{
  int newcapacity = 2 * this->capacity;
  T *temp = (T *)malloc(sizeof(T) * newcapacity);
  if (temp == nullptr)
  {
    throw std::bad_alloc();
  }
  else
  {
    for (int i = 0; i < this->size; i++)
    {
      new (&temp[i]) T(this->arr[i]);
    }
    for (int i = 0; i < this->size; i++)
    {
      this->arr[i].~T();
    }
    free(this->arr);
    this->arr = temp;
    this->capacity = newcapacity;
  }
}
template<typename T>
void DynamicArray<T>::shrink(){
  if(size == 0){
    free(this->arr);
    this->arr = nullptr;
    this->capacity = 0;
    return;
}
  int newCapacity=this->capacity/2;
  T* temp=(T*)malloc(sizeof(T)*newCapacity);
  if(temp==nullptr){
    throw std::bad_alloc();
  }
  for(int i=0;i<this->size;i++){
    new(&temp[i])T(this->arr[i]);
  }
  for(int i=0;i<this->size;i++){
    this->arr[i].~T();
  }
  // this.~DynamicArray();
  free(this->arr);
  this->arr=temp;
  this->capacity=newCapacity;
}

template <typename T>
void DynamicArray<T>::append(const T& data)
{
  if (this->capacity == 0)
  {
    int newcapacity = 10;
    this->arr = (T *)malloc(sizeof(T) * newcapacity);
    if (this->arr == nullptr)
    {
      throw std::bad_alloc();
    }
    else
    {
      this->capacity = newcapacity;
    }
  }
  else if (this->size == this->capacity)
  {
    regrow();
  }
  new (&this->arr[this->size]) T(data);
  this->size++;
}
template<typename T>
void DynamicArray<T>::insert(int index,const T& data){ 
  if(index<0||index>size){
    throw std::out_of_range("Invalid insert index");
  }
  if(size==capacity){
    if(capacity==0){
    int newcapacity=10;
    T* temp=(T*)malloc(sizeof(T)*newcapacity);
    if(temp==nullptr){
    throw std::bad_alloc();
    }else{
      this->arr=temp;
      this->capacity=newcapacity;
    }
    }else{
    regrow();
    }
  }
  if(index<size){
    new(&this->arr[size])T(this->arr[size-1]);
    for(int i=size-1;i>index;i--){
      this->arr[i]=this->arr[i-1];
    }
     this->arr[index]=data;
  }else{
    new(&this->arr[size])T(data);
  }
  this->size++;
}
template<typename T>
void DynamicArray<T>::remove(int index){
  if(index<0||index>=this->size){
    throw std::out_of_range("Invalid remove Index");
  }else{
   
    if(index<this->size-1){
      for(int i=index;i<this->size-1;i++){
        this->arr[i]=this->arr[i+1];
      }
    }
    this->arr[size-1].~T();
      this->size--;
      if(this->size<=this->capacity/4){
        this->shrink();
      }
  }
}
template <typename T>
const T& DynamicArray<T>::get(int index)const 
{
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("index out of range");
  }
  return this->arr[index];
}
template <typename T>
T& DynamicArray<T>::get(int index) 
{
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("index out of range");
  }
  return this->arr[index];
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray &other){
// std::cout << "DynamicArray assignment this=" << this
//           << " other=" << &other << '\n';
  if(this==&other){
    return *this;
  }
  for(int i=0;i<this->size;i++){
    this->arr[i].~T();
  }
  free(this->arr);
  this->arr=nullptr;
  this->size=other.size;
  this->capacity=other.capacity;
  if(this->capacity==0){
  this->arr=nullptr;
  return *this;
  }
  // this->arr=nullptr;
  T* temp=(T*)malloc(this->capacity*sizeof(T));
  if(temp==nullptr){
    throw std::bad_alloc();
  }
    this->arr=temp;
  for(int i=0;i<this->size;i++){
    new(&this->arr[i])T(other.arr[i]);
  }
  return *this;
}