#include<iostream>
using namespace std;
 class node {

    public :

    int data;
    node * previous = NULL;
    node * next= NULL;

    node ( int d){
        this ->data=d;
        this->next=NULL;
        this->previous=NULL;
    }
 };

 void print( node * &head){

    node * temp= head;

    while ( head!=NULL){
        cout<<temp->data<<" ";
        cout<<temp->next<<" ";
        cout<<temp->previous<<"  ";
        temp=temp->next;
        
    }
    cout<<endl;

 }

 int getlength( node * head){
    int len=0;
    node* temp= head;
    while ( temp!=NULL){
        len++;
        temp=temp->next;

    }
    return len;
 }

    void insertAThead( node *&head, int data){

        node * temp= new node(data);
        temp->next=head;
        head->previous=temp;
        head=temp;
    }

    void insertATtail( node * &tail, int value){

        node * temp= new node (value);
        tail->next=temp;
        temp->previous=tail;
        tail=temp;
    }
    void INSERTATPOSITION ( node* &head,node *&tail, int value , int position){
         if ( position==0){
            insertAThead(head, value);
            return;
         }
         
         node * temp= head;
         node * newnode= new node (value);
         int count=0;
         if (temp->next=NULL){
            insertATtail(tail,value);
         }
         while ( count!=position-1){
            temp= temp->next;
            count++;
         }
         newnode->next= temp->next;
         temp->next->previous= newnode;
        temp->next=newnode;
        newnode->previous=temp;
    }

    void DELETE(node* &head, int position){
        if (position ==1){  
        node *temp= head;
        temp->next->previous= NULL;
        head=temp->next;
        temp->next=NULL;
        free(temp);}
        else {
             
            int count=0;
            
            node *current=head;
            node * previous=NULL;
            while ( count<position){
                current=previous;
                current=current->next;
                count++;
            }
            //here we have reahed our node whuch has to be deleted
            current ->previous=NULL;
            previous->next=current->next;
            current->next=NULL;
            free(current);


        }

    }


int main(){
    node * node1= new node(10);
    node *head= node1;
    node* tail=node1;
    cout<<getlength<<endl;
     print (head);
    insertAThead(head, 50);
     print(head);
    insertATtail(tail, 65);
   print(head);
    INSERTATPOSITION(head,tail,20,1);
    print(head);
    DELETE(head, 2);
    print(head);

}