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
void DoublyLinkedList<T>::insertItem(T &item) {
  auto *newNode = new NodeType<T>;

  newNode->data = item;
  newNode->next = nullptr;
  newNode->back = nullptr;

  if (this->head == nullptr) {

	this->head = newNode;
	this->tail = newNode;

  } else if (item < this->head->data) {

	NodeType<T> *temp = this->head;
	this->head = newNode;
	newNode->next = temp;
	temp->back = head;

  } else {

	NodeType<T> *temp = this->head;
	NodeType<T> *prev = nullptr;
	bool insertionCompleted = false;

	while (temp != nullptr) {
	  if (item < temp->data) {

		newNode->back = temp->back;
		newNode->next = temp;
		temp->back = newNode;

		if (newNode->back != nullptr) {
		  newNode->back->next = newNode;
		}

		insertionCompleted = true;

		break;
	  }

	  prev = temp;
	  temp = temp->next;
	}

	if (!insertionCompleted) {
	  newNode->back = prev;
	  prev->next = newNode;
	  this->tail = newNode;
	}

  }
}

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T> *t = head;
  while(t!=NULL){
	if(t->data==item){
	  break;
	}

	t = t->next;
  }
  if(t!=NULL){
	if(t->next==NULL && t->back==NULL){
	  free(t);
	  head = NULL;
	  tail = NULL;
	}
	else if(t->back == NULL){
	  head = head->next;
	  head->back = NULL;
	  free(t);
	}
	else if(t->next==NULL){
	  tail = tail->back;
	  tail->next=NULL;
	  free(t);
	}
	else{
	  NodeType<T> *p, *n;
	  p = t->back;
	  n = t->next;
	  p->next = n;
	  n->back = p;
	  free(t);
	}

  }
  else {
	cout<<"Item not in list!"<<endl;
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
  if(tail==NULL){
	cout<<"List is Empty!"<<endl;
  }
  else{
	NodeType<T> *t = tail;
	while(t!=NULL){
	  cout<<t->data<<" ";
	  t = t->back;
	}
  }
}
template<class T>
void DoublyLinkedList<T>::sorting(T &item) // ı call sorting function in the insertion function
{
  auto *newNode = new NodeType<T>;
  newNode->data = item;
  newNode->next = nullptr;
  newNode->back = nullptr;

  NodeType<T> *current = head;

  if (head == nullptr && tail == nullptr) { // newNode is being inserted into empty list
	head = newNode;
	tail = newNode;

	length++;

	return;
  }

  bool isDuplicate = false;
  while (current != nullptr) {
	if (head->data > item) // keep going
	  current = current->next;
	break;
  }

  if (current == nullptr) { // newNode is being inserted as last element
	tail->next = newNode;
	newNode->back = tail;

	tail = newNode;

	length++;
  }

	// newNode is being inserted into very beginning
  else if (current->back == nullptr) {
	newNode->next = current;
	current->back = newNode;

	head = newNode;

	length++;
  } else if (!isDuplicate) { // general case insert
	newNode->back = current->back;
	current->back->next = newNode;
	newNode->next = current;
	current->back = newNode;

  }
  length++;
}
template<class T>
int DoublyLinkedList<T>::lengthIs() const {
	int l=0;
	NodeType<T> *t = head;
	while(t!=NULL){
	  l++;
	  t = t->next;
	}
	return l;
  }

//int DoublyLinkedList<T>::countIs() const {
//  return count;
//}
template<class T>
T DoublyLinkedList<T>::mode() {
  NodeType<T> *currentSearchNode = this->head;
  NodeType<T> *tempNode;
  T mode = this->head->data;
  int maxOccurences = -1;
  int occurences;

  while (currentSearchNode != nullptr) {
	occurences = 0;
	tempNode = this->head;

	while (tempNode != nullptr) {
	  if (tempNode->data == currentSearchNode->data) {
		occurences++;

	  }
	  tempNode = tempNode->next;
	}

	if (occurences > maxOccurences) {
	  maxOccurences = occurences;
	  mode = currentSearchNode->data;
	}

	currentSearchNode = currentSearchNode->next;
  }
  return mode;

}

template<class T>
void DoublyLinkedList<T>::swapAlternate() {
  if (head == nullptr || head->next == nullptr)
	return;
  NodeType<T> *prev = head;
  NodeType<T> *curr = head->next;
  head = curr;
  while (true) {
	NodeType<T> *next = curr->next;
	curr->next = prev;
	if (next == nullptr || next->next == nullptr) {
	  prev->next = next;
	  break;
	}
	prev->next = next->next;
	prev = next;
	curr = prev->next;
  }

}
template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &item1, T &item2) {

  NodeType<T> *f;
  if (head == nullptr) {
	return;
  }
  if (head->data > item2) {
	return;
  }
  if (tail->data < item1) {
	return;
  }
  f = head;
  while (f != nullptr && f->data < item1) {
	f = f->next;
  }
  if (f != nullptr) {
	if (f->back == nullptr && f->next == nullptr) {
	  head = nullptr;
	  tail = nullptr;
	  free(f);
	  return;
	} else if (f->back == nullptr) {
	  head = head->next;
	  head->back = nullptr;
	  free(f);
	  deleteSubsection(item1, item2);
	  return;
	} else if (f->next == nullptr) {
	  tail = tail->back;
	  tail->next = nullptr;
	  free(f);
	  return;
	} else {
	  NodeType<T> *p = tail;
	  while (p != nullptr && p->data > item2) {
		p = p->back;
	  }
	  if (p->next == f) {
		return;
	  } else {
		f->back->next = p->next;
		if (p->next != nullptr) {
		  p->next->back = f->back;
		}
		NodeType<T> *t;
		while (f != p) {
		  t = f;
		  f = f->next;
		  free(t);
		}
		free(f);
	  }
	  return;
	}
  }
}
template<class T>
T DoublyLinkedList<T>::*delete_index(T &item) {
  NodeType<T> *next;
  NodeType<T> *head;
  if (head == nullptr)
	return head;
  next = head->next;
  return item == 0 ? (free(head), next)
				   : (head->next = delete_index(next, item - 1), head);
}

template
class DoublyLinkedList<int>;
template
class DoublyLinkedList<float>;
template
class DoublyLinkedList<std::string>;