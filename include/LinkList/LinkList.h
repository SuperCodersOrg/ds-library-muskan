#ifndef LINKLIST_H
#define LINKLIST_H
template <typename T>
class LinkList{
  private:
  int size;
  struct Node{
    T data;
    Node* next;
    Node(const T& data){
      this->data=data;
      next=nullptr;
    }
  };
  Node* head;
  Node* tail;
  public:
  LinkList();
  ~LinkList();
  void insertFront(const T& value);
  void insertBack(const T& value);
  void insert(int index,const T& value);
  void deleteFront();
  void deleteBack();
  void removeAt(int index);
  bool removeValue(T value);
  void clear();
  const T& getFront();
  const T& getBack();
  const T& get(int index);
  void set(int index,const T& value);
  int getSize();
  bool isEmpty();
  void print() const;

};
#include "LinkList.cpp"
#endif