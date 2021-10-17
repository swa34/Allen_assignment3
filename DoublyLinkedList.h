//
// Created by scott on 10/8/2021.
//

#ifndef ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
#define ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
#include <initializer_list>
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
  int count{};
  NodeType<T> *head;
  NodeType<T> *current;
  NodeType<T> *tail;
  NodeType<T> *listData;

 public:

  DoublyLinkedList();
   ~DoublyLinkedList();
  int lengthIs() const;
  void insertItem(T &item);
  void deleteItem(T &item);
  void resetList();
  void print();
  auto getValue();
  void initialize(T num);
  void printReverse();
  void sorting(T &item);
  T searchForL(T item);
  void swapAlternate();
  T mode();
  void printRange(NodeType<T> *startingNode, NodeType<T> *endingNode);
  void deleteSubsection(T &item1,T &item2);
  T *delete_index(T &item);
// int countIs()const;
//  bool findItem( T, NodeType<T>*& predecessor)
 private:
  int value{};

};

#endif //ALLEN_ASSIGNMENT3__DOUBLYLINKEDLIST_H_
