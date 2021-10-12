#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  length = 0;
  head = nullptr;
  listData = nullptr;
}

template<class T>
void DoublyLinkedList<T>::insertItem(T item) {
  auto *newNode = new NodeType<T>;
  newNode->data = item;
  newNode->next = nullptr;
  newNode->back = nullptr;
  //auto current = head;
  if (head == nullptr) {
	head = newNode;
  } else if (head->data > item) {
	NodeType<T> *temp = head;
	head = newNode;
	newNode->next = temp;
	temp->back = head;
  } else {
	NodeType<T> *temp = head;
	NodeType<T> *prev = nullptr;
	bool inserted = false;
	while (temp != nullptr) {
	  if (temp->data > item) {
		//Node* _temp = temp;
		newNode->back = temp->back;
		newNode->next = temp;
		temp->back = newNode;
		if (newNode->back != nullptr) {
		  newNode->back->next = newNode;
		}
		inserted = true;
		break;
	  }
	  prev = temp;
	  temp = temp->next;
	}
	if (!inserted) {
	  newNode->back = prev;
	  prev->next = newNode;
	}
  }
}
template<class T>
void DoublyLinkedList<T>::deleteItem(T &item){
  if (head == NULL)
  {
	return;
  }
  else {
	if (head->data == item)
	{
	  NodeType<T> *temp = head;
	  head = head->next;
	  if (head != nullptr)
		head->back = nullptr;
	  delete(temp);
	}
	else {
	  NodeType<T> *temp = head->next;
	  while (temp != nullptr)
	  {
		if (temp->data == item)
		{
		  {
			temp->back->next = temp->next;
			if (temp->next != nullptr)
			  temp->next->back = temp->back;
		  }
		  NodeType<T>* toDelete = temp;
		  temp = temp->back;
		  if (toDelete != nullptr)
			delete(toDelete);
		}
		temp = temp->next;
	  }
	}
  }
}

template<class T>
void DoublyLinkedList<T>::print() {
  NodeType<T> *elem = head;
  while (elem != nullptr) {
	cout << elem->data << " ";
	elem = elem->next;
  }
//cout << endl;
}

template<class T>
void DoublyLinkedList<T>::printReverse() {
//
//  NodeType<T>*elem =head;
//  while(elem != nullptr){
//	cout << elem->data << " ";
//	elem = elem->next;
//  }
//  //cout << endl;
//}

  while (tail != nullptr) {
	cout << tail->data << " ";
	tail = tail->back;

  }
}

template
class DoublyLinkedList<int>;
template
class DoublyLinkedList<float>;
template
class DoublyLinkedList<std::string>;