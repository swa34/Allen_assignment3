#include <iostream>
#include <cstring>
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
  //if()
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
  NodeType<T> *temp = NULL;
  NodeType<T> *current = head;

  /* swap next and prev for all nodes of
  doubly linked list */
  while (current != NULL)
  {
	temp = current->back;
	current->back = current->next;
	current->next = temp;
	current = current->back;
  }

  /* Before changing the head, check for the cases like empty
	  list and list with only one node */
  if(temp != NULL )
	head = temp->back;
}
template<class T>
void DoublyLinkedList<T>:: sorting(  T &item) // ı call sorting function in the insertion function
{
  NodeType<T>* newNode = new NodeType<T>;
  newNode->data = item;
  newNode->next = nullptr;
  newNode->back = nullptr;

  NodeType<T>* current = head;

  if(head == nullptr && tail == nullptr) { // newNode is being inserted into empty list
	head = newNode;
	tail = newNode;

	length++;

	return;
  }

  bool isDuplicate = false;
  while(current != nullptr) {
	if(head->data > item) // keep going
	  current = current->next;
	  break;
	}


  if(current == nullptr ) { // newNode is being inserted as last element
	tail->next = newNode;
	newNode->back = tail;

	tail = newNode;

	length++;
  }

	// newNode is being inserted into very beginning
  else if(current->back == nullptr ) {
	newNode->next = current;
	current->back = newNode;

	head = newNode;

	length++;
  }

  else if(!isDuplicate) { // general case insert
	newNode->back = current->back;
	current->back->next = newNode;
	newNode->next = current;
	current->back = newNode;

	length++;
  }
}






template
class DoublyLinkedList<int>;
template
class DoublyLinkedList<float>;
template
class DoublyLinkedList<std::string>;