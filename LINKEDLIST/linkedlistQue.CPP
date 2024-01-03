// Q1- GIVEN THE HAED OF THE OF LINKED LIST, DELETE EVERY ALTERNaTE ELEMENT FROM THE LOST STARTING FROM THE SECOND ELEMENT..
// Q2-> GIVEN THE HEAD OF A SORTED LINKLIST , DELETE ALL DUPLICATES SUCH THAT EACH ELEMENT APPERAS ONLY ONCE .RETURN THE LINK LIST SORTED AS WELL
// Q3-> GIVEN THE HEAD OF THE SINGLY LINKED LIST , REVERSE THE LIST AND RETURN THE REVERSED LINKED LIST
#include<iostream>
using namespace std;

class node{
    public:
    int value ;
    node * next;

    node (int data){
        this->value=data;
        this->next=NULL;
    }
};

class linkedlist{

    public:
    node* head;

    linkedlist(){
        head=NULL;
    }
};

void insertATtail( node * &head, int data){
    node* newnode= new node(data);
    node*temp=head;
    if( head==NULL){
        head= newnode;
        return;}
        while( temp->next!=NULL){
            temp= temp->next;
        }
        temp->next= newnode;
}

void print( node*&head){
    node *temp=head;
    while (temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtalternate( node* &head){ //   <- Q1 ->ANS  ALTERNATE DELETING NODES; 
    node * current= head;
    while ( current!=NULL && current->next!=NULL){
        node *temp= current->next;
        current->next= current->next->next;
        free( temp);
        current=current->next;
    }
}

void deleteduplicate( node* head){   // <- Q2 ANS   this function delets the duplicate elements in the linked list node
    node * current= head;
    while (current!=NULL){
        while ( current->next!= NULL&& current->value== current->next->value){
            //delete current->next
            node* temp= current->next;
            current->next= current->next->next;
            free(temp);

            
        }
        // this loops end when current node and next node value is diffrent 
        current=current->next;
    }


    }
    void reverseprint( node * &head){
        // BASE CASE->
        if ( head ==NULL){
            return;
        }
        reverseprint( head->next);  //  RECURSIVE CALL
        cout<<head->value<<endl;  // HERE WE HAVE PRINT THE LINKED LIST IN THE REVRSE ORDER

        }

        node* reverselinkedlist( node * &head){     // reversing the linked list


            node * previous=NULL;
            node * currentptr=head;
            while ( currentptr!=NULL){
                node * next= currentptr->next;
                currentptr->next=previous;
                previous=currentptr;
                currentptr= next;
            }
            // WHEN THIS LOOP ENDS MY PREVIOUSPOINTER WILL POINT TO THE LAST NODE WHICH IS MY NEW HEAD
            node * temp= previous;
            return temp;   // here temp is my new head thats why 
        }

        node * reverseRECURSION( node * &head, node *current, node * previous){
            node * previous=NULL;
            node * current= head;
            node * forward= current->next;
            if ( current==NULL){
                head= previous;
                return;
            }
            reverseRECURSION( head, forward, current);
            current->next=previous;
            
            
        }

        int getlength( node * &head){
            node *temp= head;
            int length=0;
            while ( temp!=NULL){
                length++;
                temp=temp->next;
            }
            return length;
        }
        int getmiddle( node * &head){       // to return middle of the linked list
            int len = getlength(head);
            int ans= (len/2);
            node*temp= head;
            int count=1;
            while ( count<ans){
                temp=temp->next;
                count++;
            }
        
        return ans;
        }

int main(){
    node*head=NULL;

    linkedlist l1;
    insertATtail(head,2);
    insertATtail(head,3);
    insertATtail(head,3);
    insertATtail(head,5);
    insertATtail(head,6); 
    print(head);
    deleteAtalternate(head);
    print( head);
    deleteduplicate(head);
    print( head);
    reverseprint(head);
    l1.head= reverselinkedlist(head);
    print ( head);
    getmiddle(head);
    print(head);


}