/*CIRCULAR LINKED LIST -> IT IS JUST A SINGLY LINEKD LIST BUT IN THIS THE LAST NODE RATHER THAN POINTING TOWARDS THE 
NULL WILL POINT TO FIRST NODE*/

#include<iostream>
using namespace std;

class node {

    public:
    int data;
    node * next;


    node (int data){
        this->data=data;
        this->next=NULL;
    }

    ~node( ){
    int value = this->data;


    if (this->next!=NULL){
        delete next;
        next=NULL;
// here in circular linked list by just using the tail i can acces the head as well asthe tail no nee dto make the head
    }
    cout<<" the memory is free with this data"<<endl;
}
};

void print( node * &tail){
    node *temp= tail;
    do{
        cout<<tail->data<<" ";   // for single node 
        tail=tail->next;
    }
    while ( tail->next!=temp);
    cout<<" ";
}
void insertnode ( node *&tail, int element, int data){
    
    if (tail==NULL){ // empyty list
        node *temp= new node (data);
        temp->next=temp;
        temp=tail;
    }
    else {  //  NON EMPYTY LIST
        node *current= tail;
        while ( current->data!=element){
            current=current->next;
        }
        //element found
        node *temp= new node (data);
        temp->next= current->next;
        current->next=temp;

        // BY THIS WE HAVE DONE INSERTION IN CIRCULAR LINKED LIST

    }

    }
    void deletenode( node * &tail, int value ){
        //EMPYTY LIST
        if (tail==NULL){
            cout<<" the list is empyty"<<endl;
            return;
        }
        else {
           //NON EMPTY LIST
           // ASSUMING THAT THE VALUE IS PRESENT IN THE LINKED LIST
           node * previous= tail;
           node * current= previous ->next;
           while ( current->data!=value){
            previous=current;
            current=current->next;
           }
           previous->next=current->next;
           current->next=NULL;
           delete(current);

            
        }
    }


int main(){
    node *tail= NULL;
    insertnode(tail,10,20);
    print(tail);
    insertnode(tail,10,30);
    print(tail);
    insertnode(tail,10,40);
    print(tail);
    insertnode(tail,10,50);
    print(tail);
    insertnode(tail,10,70);
    print(tail);
    insertnode(tail,10,80);
    print(tail);
    deletenode(tail,10);
    print(tail);
    deletenode(tail,80);
    print(tail);
    
}
