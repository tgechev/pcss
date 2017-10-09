#include <iostream>
#include "LinkedList.h"
#include "Node.h"

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
    int i = 1;
    NodePtr temp=head;
    //temp=head;
    while(temp!=NULL)
    {
      cout<<"Node "<<i<<": "<<temp->data<<"\n";
      temp=temp->next;
      i++;
    }
  }
  void LinkedList::insert_start(int value)
  {
    NodePtr temp=new Node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }
