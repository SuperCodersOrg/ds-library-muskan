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
    throw std::invalid_argument("capacity must be positive");
  }
  this->size = 0;
  this->capacity = capacity;
  this->arr = (T *)malloc(sizeof(T) * this->capacity);
  if (this->arr == nullptr)
  {
    throw std::bad_alloc();
  }
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
template <typename T>
void DynamicArray<T>::append(T data)
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
template <typename T>
T DynamicArray<T>::get(int index)
{
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("index out of range");
  }
  return this->arr[index];
}