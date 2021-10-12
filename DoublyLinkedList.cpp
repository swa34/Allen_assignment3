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
  auto *newNode = new NodeType<T>;
  newNode->data = item;
  newNode->next = NULL;
  newNode->back = NULL;
  auto current = head;
  if (head == nullptr) {
	head = newNode;
	tail = newNode;

  }else {
	head->back = newNode;
	newNode->next = head;
	head = newNode;
  }
  length++;
}
template <class T>
void DoublyLinkedList<T>::print() {

  while (tail != NULL) {
	cout << tail->data << " ";
	tail = tail->back;

  }
}


//template <class T>
//auto DoublyLinkedList<T>::getValue()  {
// return value;
//}
template <class T>
void DoublyLinkedList<T>::printReverse() {

  NodeType<T>*elem =head;
  while(elem != NULL){
	cout << elem->data << " ";
	elem = elem->next;
  }
  //cout << endl;
}







template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;