#include <iostream>
using namespace std;

/* LINKED LIST--> IT IS A LINEAR DATA STRUCTURE WITH A COLLECTION OF NODES ( NODES--> ENCAPSULATION OF DATA AND NEXT DATA ADRESS) 
  -->IT IS A DYNAMIC DATA STRUCTE AND CAN BE CHANGED AT THE RUNTIME ( EXPAND OR SHRINK) NO MEMORY IS WASTED IN IT..
  -->INSERTION AND DELETION IS EASY NO SHIFING HAPPENS..

  TYPES OF LINKED LIST -->
  -> SINGLY LINKED LIST 
  -> DOUBLY LINKED LIST
  -> CIRCULAR LINKED LIST
  -> CIRCULAR DOUBLY LINKED LIST ..*/

  class Node {
    public :

    int data;
    Node* next;

  // constructor--->>
    Node( int data){
        this->data=data;
        this-> next =NULL;
    }
  };

    // insertion in a linkedlist
    void insertAthead( Node* &head , int data  ){  // HERE REFRENCE IS TAKEN  BEACUASE I DONT WANT TO MAKE COPY
       Node *temp= new Node (data); // new node temp name ;
       temp -> next  = head;  // temp adress is point towards head adress
       head= temp; // head is positioned to temp

}

  void insertAttail( Node* tail , int data){ // insertion at tail
    Node *temp= new Node (data);
    tail ->next=temp;
    tail=temp;

  }

  void insertatposition(  Node*head,int position , int data ){
    Node* temp= head;
    int count =1;
    while ( count <position){
      temp=temp->next;
      count ++; }
      Node * nodetoinsert= new Node(data);
      nodetoinsert-> next = temp-> next;
      temp -> next = nodetoinsert;

    
  }
    


  
   int main(){

    Node* Node1= new Node(10); // heap memory me create hua h
    cout<<" node 1 data is "<< Node1->data<<endl;   // (->) beacuase of pointer 
    cout<<"node 1 next adrees is "<< Node1->next<<endl;
    Node* head= Node1;
    Node* tail=Node1;
    insertAthead( head,12);
    insertAttail( tail, 15);
    insertatposition( head, 5, 20);
    

   



   }