#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
DoublyLinkedList<T>:: DoublyLinkedList(){
  length = 0;
  head = NULL;
  listData=NULL;
}

template <class T>
void DoublyLinkedList<T>::insertItem(T item) {
  auto *newNode = new NodeType<T>[1];
  newNode->data = item;
  newNode->next = NULL;
  newNode->back = NULL;
  auto current = head;
  if (head == NULL) {
	head = newNode;
	return;
  }
  head->back = newNode;
  newNode->next = head;
  head = newNode;
}
template <class T>
void DoublyLinkedList<T>::print(){
  NodeType<T>*elem =head;
  while(elem != NULL){
	cout << elem->data << " ";
	elem = elem->next;
  }
  //cout << endl;
}


//template <class T>
//auto DoublyLinkedList<T>::getValue()  {
// return value;
//}
template <class T>
void DoublyLinkedList<T>::printReverse() {
  auto *newNode = new NodeType<T>;
 // newNode->data = item;
  newNode->next = NULL;
  newNode->back = NULL;
  auto current = head;
  if (head == NULL) {
	head = newNode;
	return;
  }
  head->back = newNode;
  newNode->next = head;
  head = newNode;
}







template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;