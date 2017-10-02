#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Node.h"
class LinkedList
  {
  private:
    NodePtr tail, head;
  public:
    LinkedList();
    void createNode(int value);
    void display();
    void insert_start(int value);
  };
#endif // LINKEDLIST_H_INCLUDED
