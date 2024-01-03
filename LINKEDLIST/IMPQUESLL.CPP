/* QUE-> ASKED IN MICROSOFT  ->  YOU HAVE BEEN GIVEN A LINKED LIST WITH NO OF NODES YOU HAVE TO REVRSE THE LINKED LIST WITH Kth GROUP 
WHICH MEANS THAT THE SUPPOSE THE K VALUE IS GIVEN TO BE 2 THEN IN EACH TWO FROUPS REVERSE THE LINEKD LIST
Q-2-> IS CIRCULAR OR NOT
 */
 #include<iostream>
 #include<map>
 #include<vector>
 using namespace std;
class node {
    public:


    public:
    int data;
    node * next;

    node (int value){
        this->data=value;
        this->next= NULL ;
    }
     

};
node* kReverse(node* head, int k) {    // kth reverse;
    // base case
    if ( head==NULL){
        return NULL;
    }
    // step-1->reverse first k nodes 
    node * current= head;
    node * previous =NULL;
    node * next= NULL;
    int count=0;
    while ( count < k  && current!=NULL){
        next=current->next;
        current->next=previous;
        previous = current;
        current= next;
        count++;
        }
        // step->2 recursive call
        if ( next!=NULL){
            head->next=kReverse(next, k);
        }
        // step-3-> return head 
        return previous;// as previous will be the head
}
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
void print( node*&tail){
    node *temp=tail;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool iscircularlist( node * head){    // THIS CODE TELLS THAT WHETHER THE LINKED LIST IS CIRCULAR OR NOT;
    // empyty list
    if ( head==NULL){
        return true;
    }
    // single node and multi nide code is same 
    node * temp= head->next;
    while ( head->next !=NULL && head!=temp){
        temp= temp->next;
    }
    if (temp== head ){
        return true;
    }
    if ( temp== NULL){
        return false;
    }

}
               // VERY IMPORTANT
bool detectloop( node * &head){      // this fn detects the loop in the list
     
if  (head==NULL)
return false;
map < node*, bool> visited;
node * temp= head;
while ( temp!=NULL){
    // cycle is present
    if (visited[temp]==true){
        return 1;
    }
    visited[temp]=true;
    temp=temp->next;

}
return 0;

}

//   THERE IS ANOTHER METHOD TO DETECT LOOP NY USING FLOYDS CYCLE METHOD

 node * floydcycle( node * &head){    
    if ( head==NULL){
        return NULL;
    }
    node * slow =head;
    node * fast = head;
    while ( slow !=NULL && fast!=NULL){
        fast=fast->next;
        if ( fast !=NULL){
            fast=fast->next;
        }
        slow= slow ->next;
        if ( slow == fast){
            cout<<" loop is present at "<<slow->data<<endl;
            return slow;
        
        }
        }
        return NULL;
        
}

node * detectstartingnode( node * head){
    if ( head == NULL){
        return NULL;
    }
    node * slow = head;
    node * fast = head;
    node* intersection=floydcycle(head);
     // after getting cycle the slow and fast are at some common node
     slow =head;
     while (slow !=intersection){
     slow = slow->next;
     intersection = intersection ->next;
     
     }
     // AFTER COMPLETING THIS LOOPS WE HAVE REACHED TO OUR NODE 
     return slow;
}
     node * removeloop( node * head){
        if (head==NULL) {
            return NULL;
    
        }
        node * startingnode = detectstartingnode(head);
        node * temp= startingnode;
        while ( temp->next != startingnode){
            temp=temp->next;
        }
        temp->next=NULL;
     }
     // NEXT QUESTION -> DETECT THE DUPLICATES IN THE sorted    linked list 
     
    node * deleteduplicate( node * &head){
        if  (head==NULL)
        return NULL;
    
    node * temp= head;
    while( temp!=NULL && temp->next!=NULL){
        if ( temp->data==temp->next->data){
            node * duplicate= temp->next;
            temp->next= temp->next->next;
            free(duplicate);
        }
        else {
            temp=temp->next;
        }

    }
    return head;

    
}// NEXT QUESTION -> DETECT THE DUPLICATES IN THE UNsorted    linked list 
node * deleteduplicateunsorted(node*head){
if (head==NULL){
        return NULL;
    }
    node * current= head;
    while( current!=NULL){
        node * temp= current->next;
        while(temp!=NULL){
            if (current->data==temp->data){
                node * duplicate= temp->next;
                temp->next=temp->next->next;
                free(duplicate);
            }
            else{
                temp=temp->next;
            }
            
        }
    }
    return head;  
}
 // BUT THIS PROGRAM WILL CAUSE AN RUNTIME ERROR AS ITS COMPLEXITY IS O(NSQUARE);

 // 2ND APPROACH->
 node *removeDuplicates(node *head)
{
    if (head==NULL){
        return NULL;
    }
    map<node*,bool>visited;  // BY USING MAPS
    node *temp=head;
    while (temp != NULL) {
        if (visited[temp] = true) {
          node *duplicate = temp->next;
          temp->next = temp->next->next;
          free(duplicate);
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return head;
}
//  NEXT QUESTION->TOO SORT THE LINEKD LIST IN THE 0S,1S AND 2S ORDER;->
 node* sortList(node *head){
    int zerocount=0;
    int onecount= 0;
    int twocount=0;
    node *temp= head;
    while(temp!=NULL){
        if (temp->data==0){
            zerocount++;
        }
        else if(temp->data==1){
            onecount++;
        }
        else if(temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if ( zerocount!=0){
            temp->data=0;
            zerocount--;
        }
        else if( onecount!=0){
            temp->data=1;
            onecount--;
        }
         else if (twocount!=0){
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
    return head;
}

// IMPORTANT QUESTION -> CHECK WHETHER THE LINKED LIST IS PALINDROME OR NOT
//1ST APPROACH->
// BY USINGA ND ARRAY

node * palindrome(node *head){
 vector<int>arr;
 node *temp=head;
 while (temp!=NULL){
    arr.push_back(temp->data);
    temp=temp->next;
 }
 int s=0;
 int e=arr.size()-1;
 while(s<=e){
 if(arr[s]!=arr[e])
{
   cout<<"not a palindrome";
}
// this will take the complexity O(n);
}}

// NEXT BETTER APPROACH->

/*step-1> find middle
step->2->do reverse the linked list sfter middle
step->check head 1 == head 2;
and return wherterh it is p[lindrkme or not*/

node * getmid(node*head){
    node *slow=head;
    node* fast= head->next;
    while (fast->next !=NULL && slow!=NULL){
        slow=slow->next;
        if (fast->next!=NULL){
            fast=fast->next->next;
        }
        return slow;
    }
}
node *reverse(node *head){
    node *previous=NULL;
    node *current= head;
    node *next=NULL;
    while( next!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    return previous;
}
bool checkpalindrome(node *head){
if (head->next==NULL){
    return true;
}
node *middle=getmid(head);
node *temp=middle->next;
middle->next=reverse(temp);
node *head1=head;
node *head2=middle->next;
while (head2!=NULL){
    if (head1->data!=head2->data){
        return false;
    }
    head1=head1->next;
    head2=head2->next;
    temp=middle->next;
    middle->next=reverse(temp);
}
return true; 

}



int main(){
    node * node1= new node (0);
    node *tail= node1;
    node *head= node1;

    insertATtail(tail,2);
    insertATtail(tail,2);
    insertATtail(tail,1);
    insertATtail(tail,1);
    insertATtail(tail,0);
    
    /* if  ( floydcycle(head)!=NULL){
        cout<<" cycle is present"<<endl;
     }
     else cout<<" no cycle"<<endl;
    
    cout<<" starting at"<<detectstartingnode(head)->data<<endl;
    removeloop(head);
    deleteduplicate(head);
    print(head);*/
    sortList(head);
    print(head);




}