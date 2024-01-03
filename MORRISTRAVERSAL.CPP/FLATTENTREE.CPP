#include<iostream> 
using namespace std ;

class Node{

    int data;
    Node *left;
    Node *right;
  public:
    void flatten(Node *root)
    {
        Node * curr= root;
        while ( curr !=NULL){
             if( curr->left)
             {
                Node* pred= curr->left;
                while ( pred->right)
                    pred=pred->right;
                    
                pred->right=curr->right;
                curr->right= curr->left;
                curr->left=NULL;
                
                
            }
            curr=curr->right;
            
        }}
        
    };
    int main(){
        Node * temp = new Node ();

    }