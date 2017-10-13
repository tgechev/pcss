#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList(){
    length=0;
    head=NULL;
    tail=NULL;
}
int LinkedList::getLength(){
    return length;
}
void LinkedList::createNode(int value){
      NodePtr temp=new Node;
      temp->data=value;
      temp->next=NULL;

      if(head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
        }
      else{
        tail->next=temp;
        tail=temp;
        }
        length++;
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
    if(head==NULL){
        this->createNode(value);
    }
    else{
        NodePtr temp = new Node;
        temp->data=value;
        temp->next=head;
        head=temp;
        length++;
    }

  }
  void LinkedList::insert_position(int pos, int value){
    NodePtr prev = new Node;
    NodePtr curr = head;
    NodePtr temp = new Node;
    //curr=head;
    for(int i = 1; i<pos; i++){
        prev=curr;
        curr=curr->next;
    }
    temp->data=value;
    prev->next=temp;
    temp->next=curr;
    length++;
  }
void LinkedList::delete_first(){
    NodePtr temp = head;
    head = head->next;
    delete temp;
    length--;
}
void LinkedList::delete_last(){
    if(length==1){
        this->delete_first();
    }else{
    NodePtr current = head;
    NodePtr previous = new Node;
    while(current->next!=NULL){
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
    length--;
    }
}
void LinkedList::deletePosition(int pos){
    NodePtr current = head;
    NodePtr previous = new Node;
    for(int i = 1; i<pos; i++){
        previous=current;
        current=current->next;
    }
    previous->next=current->next;

    delete current;

    cout<<"current data: "<<current->data<<endl;
}
NodePtr LinkedList::getListHead(){
    return head;
}
