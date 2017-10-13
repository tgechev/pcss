#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Node.h"
using namespace std;
class LinkedList
  {
  private:
    int length;
    NodePtr head;
    NodePtr tail;
  public:
    LinkedList();
    void createNode(int value); //insert at the end
    void display();
    void insert_start(int value);
    void insert_position(int pos, int value);
    void delete_first();
    void delete_last();
    void deletePosition(int pos);
    int getLength();
    NodePtr getListHead();
  };
#endif // LINKEDLIST_H_INCLUDED
