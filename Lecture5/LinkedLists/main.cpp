#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList myList;

int main()
{
    // initialize temporary number and linked list length

    int temp_number=0;
    int linklist_length;

    /*if(myList.getListHead()==NULL){
        cout<<"head is null! \n";
    }

    cout<<"Adding 2 nodes with value 1\n";
    myList.createNode(1);
    myList.createNode(1);
    myList.display();

    cout<<"Current list length: "<<myList.getLength()<<endl;
    cout<<"Deleting first node\n";

    myList.delete_first();

    cout<<"Deleting last node\n";

    myList.delete_last();

    if(myList.getListHead()==NULL){
       cout<<"head is null! \n";
    }else{
        cout<<"head not null! \n"<<myList.getListHead()->data;

    }*/


    //Make the user enter the length of the linked list
    cout<<"Enter the initial length of the linked list: \n";
    cin>>linklist_length;

    // fill linked list
    for(int i=0;i<linklist_length;i++){

        // get user input for linked list
        cout<< "Enter integer for node "<<linklist_length-i<<" (of "<<linklist_length<<") in the linked list:\n";
        cin >> temp_number;
        cout<< "\n";

        myList.insert_start(temp_number);
    }

    myList.display();

    cout<<"Current linked list length: "<<myList.getLength()<<endl;


    cout<<"Enter value to be inserted in position 2: "<<endl;
    cin>>temp_number;
    cout<<endl;

    if(myList.getLength()+1==2){
        myList.createNode(temp_number);
    }else{
        myList.insert_position(2, temp_number);
    }
    //To do: If desired position is end position/tail, insert node in the end instead or something similar...
    //myList.createNode(temp_number);


    myList.display();

    cout<<"Current linked list length: "<<myList.getLength()<<endl;

    cout<<"Enter value to be inserted at the end: "<<endl;
    cin>>temp_number;
    cout<<endl;

    myList.createNode(temp_number);

    myList.display();

    cout<<"Current linked list length: "<<myList.getLength()<<endl;

    cout<<"Deleting the first node in the list: \n";

    myList.delete_first();

    myList.display();

    cout<<"Current linked list length: "<<myList.getLength()<<endl;

    cout<<"Deleting the tail node in the list: \n";

    myList.delete_last();

    myList.display();

    cout<<"Choose a position for deletion: \n";
    cin>>temp_number;

    myList.deletePosition(temp_number);

    myList.display();

    if(myList.getListHead()==NULL){
       cout<<"head is null! \n";
    }else{
        cout<<"head not null! \n"<<myList.getListHead()->data;

    }

    //myList.display();


    // return from main function
    return 0;
}
