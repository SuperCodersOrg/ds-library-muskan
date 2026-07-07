#include <cstdlib>
#include <iostream>
#include<new>
#include<stdexcept>
template <typename T>
LinkList<T>::LinkList():head(nullptr),tail(nullptr),size(0){}
template<typename T>
LinkList<T>::~LinkList(){
  Node* temp=head;
  while(temp!=nullptr){
    Node* temporary=temp;
    temp=temp->next;
    (*temporary).~Node();
    free(temporary);
  }
}
template<typename T>
void LinkList<T>::insertFront(const T& value){
  Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  if(head==nullptr&&tail==nullptr){ 
    head=newNode;
    tail=newNode;
  }else{
    newNode->next=head;
    head=newNode;
  }
  ++size;
}
template<typename T>
void LinkList<T>::insertBack(const T& value){
    Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  if(head==nullptr&&tail==nullptr){ 
    head=newNode;
    tail=newNode;
  }else{
  tail->next=newNode;
  tail=newNode;
  }
  ++size;
}
template<typename T>
void LinkList<T>::insert(int index,const T& value){
  if(index<0||index>size){
    throw std::out_of_range("Invalid Index");
  }
  if(index==0){
    insertFront(value);
    return;
  }
  if(index==size){
    insertBack(value);
    return;
  }
  Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  int i=1;
  Node* temp=head;
  while(i<index){
    temp=temp->next;
    ++i;
  }
  newNode->next=temp->next;
  temp->next=newNode;
  size++;
}
template<typename T>
void LinkList<T>::deleteFront(){
  if(size==0){return;}
  if(size==1){
    (*head).~Node();
    free(head);
    head=nullptr;
    tail=nullptr;
    --size;
    return;
  }
  Node* temp=head;
  head=head->next;
  (*temp).~Node();
  free(temp);
  --size;
}
template<typename T>
void LinkList<T>::deleteBack(){
  if(size==0){return;}
  if(size==1){
    (*tail).~Node();
    free(tail);
    head=nullptr;
    tail=nullptr;
    --size;
    return;   
  }
  Node* temp=head;
  while(temp->next->next!=nullptr){
    temp=temp->next;
  }
  Node * temporary=temp->next;
  tail=temp;
  tail->next=nullptr;
  (*temporary).~Node();
  free(temporary);
  --size;
}
template<typename T>
void LinkList<T>::removeAt(int index){
  if(index<0||index>=size){
    throw std::out_of_range("invalid argument");
  }
  if(index==0){
    if(size==1){
      tail=nullptr;
    }
    Node *temp=head;
    head=head->next;
    (*temp).~Node();
    free(temp);
    --size;
    return;
  }

  Node* temp=head;
  int i=1;
  while(i<index){
    temp=temp->next;
    ++i;
  }
  if(index==size-1){
    tail=temp;
  }
  Node* temporary=temp->next;
  temp->next=temp->next->next;
  (*temporary).~Node();
  free(temporary);
  --size;
}
template<typename T>
bool LinkList<T>::removeValue(T value){
  Node *temp=head;
  if(head==nullptr)return false;
  if(temp->data==value){
    deleteFront();
    return true;
  }
  while(temp!=nullptr){
    if(temp->next!=nullptr&&temp->next->data==value){
      // if(i==size-1){
      //   deleteBack();
      //   return true;
      // }
      Node* temporary=temp->next;
      if(temporary==tail){
        tail=temp;
      }
      temp->next=temp->next->next;
      (*temporary).~Node();
      free(temporary);
      --size;
      return true;
    }
    temp=temp->next;
  }
  return false;
}
template<typename T>
void LinkList<T>::clear(){
  Node*temp=head;
  while(temp!=nullptr){
    Node* temporary=temp;
    temp=temp->next;
    (*temporary).~Node();
    free(temporary);
  }
  head=nullptr;
  tail=nullptr;
  size=0;
}
template<typename T>
const T& LinkList<T>::getFront(){
  if(head==nullptr)throw std::out_of_range("List is empty");
  return head->data;
}
template<typename T>
const T& LinkList<T>::getBack(){
  if(head==nullptr)throw std::out_of_range("List is empty");
  return tail->data;
}
template<typename T>
const T& LinkList<T>::get(int index){
  int i=0;
  Node* temp=head;
  while(i<index){
    temp=temp->next;
    ++i;
  }
 return temp->data;
}
template<typename T>
void LinkList<T>::set(int index,const T& value){
  int i=0;
  Node* temp=head;
  while(i<index){
    temp=temp->next;
    ++i;
  }
  temp->data=value;
}
template<typename T>
int LinkList<T>::getSize(){
  return size;
}
template<typename T>
bool LinkList<T>::isEmpty(){
  return head==nullptr?true:false;
}
template<typename T>
void LinkList<T>::print() const{
  Node* temp=head;
  if(head==nullptr)std::cout<<"List is empty\n";
  while(temp!=nullptr){
    std::cout<<temp->data<<"\n";
    temp=temp->next;
  }
}