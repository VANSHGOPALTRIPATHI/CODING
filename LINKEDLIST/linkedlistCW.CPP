#include <iostream>
using namespace std;

class Node{
     public:
     int val;
     Node* next = NULL;


     Node( int data){    // CONSTRUCTOR
        this->val=data;
        this->next=NULL;

     }

    

};

 void INSERTATHEAD( Node* &head, int value){  // INSERTION AT THE STARTING 
        Node * newnode= new Node( value);
        head= newnode->next;
        head= newnode;
     }


 void INSERTATTAIL( Node * &head, int value){
    Node* newnode= new Node( value);
    Node* temp= head;
     
     while ( temp->next!=NULL){
        temp = temp->next;
}
    temp->next= newnode;
 }

 void INSERTATPOSITION ( Node* &head, int value , int position){
         if ( position==0){
            INSERTATHEAD(head, value);
            return;
         }
     Node * newnode= new Node ( value);

     int currentposition=0;
     Node* temp= head;

     while ( currentposition!=position-1){
        temp= temp->next;
        currentposition++;

     }
     temp->next= newnode->next;
     temp->next=newnode;


 }

 void UPDATEATPOSITION( Node* &head, int position, int value){

    int currentposition=0;

    Node* temp= head;
     while ( currentposition!=position){
        temp= temp->next;
        currentposition++;
     }
     // temp is now pointing to kth node ;
     temp->val= value;


 }


 void PRINT( Node* head){ // TRAVERSING THE LINKED LIST AND PRINTING IT

    Node* temp= head;
    while( temp != NULL){
        cout<<temp->val<<" ->";
        temp= temp->next;
        

    }
    cout<<"NULL";
 }

   void DELETEATHEAD( Node* &head){

      Node* temp= head;  // THIS NODE HAS TO BE DELETED 
      head=head->next;   // HEAD IS SHIFTED ONE NODE
      free(temp);        // 1ST NODE IS BEEN DELETED
   }

void DELETIONATTAIL( Node* &head){    // time complexity o(n)
   Node* secondlast=head;
   while( secondlast->next->next!=NULL){
      secondlast=secondlast->next;

   }
   Node*temp=secondlast->next;
   secondlast->next=NULL;
   free(temp);

}

void DELETEATPOSITION( Node* &head, int position){ // time worst complexity O(n);

   if ( position==0){
      DELETEATHEAD(head);
      return ;
   }
   Node *previous= head;
   int currentposition=0;
   while ( currentposition!=position-1){
      previous=previous->next;
      currentposition++;
   }
   // here we have reached to deleting position
   Node* temp= previous->next;
   previous->next= previous->next->next;
   free(temp);
}



int main(){

    Node *N1= new Node( 10);
    cout<<N1->val<<"  "<<"is the val"<<endl;
    cout<<N1->next<<"  "<<"is the adress"<<endl;
    Node * head= new Node( 15);
    PRINT(head);
    INSERTATHEAD(head, 20 );
    PRINT(head);
    INSERTATTAIL( head, 40);
    PRINT(head);
    INSERTATPOSITION ( head, 60, 1);
    PRINT(head);
    UPDATEATPOSITION( head, 2,5);
    PRINT(head);
    DELETEATHEAD(head);
    PRINT(head);
    DELETIONATTAIL(head);
    PRINT(head);
    DELETEATPOSITION(head, 1);



}