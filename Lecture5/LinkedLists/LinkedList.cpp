#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(){
    head=NULL;
    tail=NULL;
}
void LinkedList::createNode(int value)
    {
      NodePtr temp=new Node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
    {
        tail->next=temp;
        tail=temp;
    }
}
void LinkedList::display()
  {
    NodePtr temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }
  void LinkedList::insert_start(int value)
  {
    NodePtr temp=new Node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }
