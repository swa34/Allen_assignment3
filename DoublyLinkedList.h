//
// Created by scott on 10/8/2021.
//

#ifndef ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
#define ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
#include <initializer_list>
enum Comparison {LESS, GREATER, EQUAL};
using namespace std;

template<class T>
struct NodeType {
  T data;
  NodeType<T> *next;
  NodeType<T> *back;

};
template<class T>
class DoublyLinkedList {
  int length;
  NodeType<T> *head;
  NodeType<T> *current;
  NodeType<T> *tail;
  NodeType<T> *listData;

 public:
  DoublyLinkedList();
 // ~DoublyLinkedList();
 Comparison compareTo(T &item);
  DoublyLinkedList( std::initializer_list<T>&);
  int lengthIs() const;
  void retrieveItem(T &item, bool &found);
  void insertItem(T item);
  void deleteItem(T &item);
  void resetList();
  void print();
  auto getValue() ;
  void initialize(T num);
  void printReverse() ;
//  bool findItem( T, NodeType<T>*& predecessor)
 private:
  int value;

};

#endif //ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
