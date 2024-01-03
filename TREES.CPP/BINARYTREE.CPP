#include<iostream>
using namespace std;
#include<queue>

class node{
    public:
    int data;
    node * left;
    node * right;


    node ( int d){
        this ->data=d;
        this -> left=NULL;
        this ->right=NULL;
    }
};
// RECURSIVE METHOD TO BUILD A TREEE BY THIS CALL THE TREE WILL BE MADE;
    node * buildtree(node*root){
        cout<<" enter the data";
        int data;
        cin>>data;
        if (data ==-1){
            return NULL;
        }
        root = new node (data);
        cout<< " enter the data for insertion at left"<<" " <<data<<endl;
        root->left=buildtree(root->left);
        cout<< " enter the data for insertion at right"<<" " <<data<<endl;
        root->right=buildtree(root->right);
        return root;


    }
    // LEVEL ORDER TRAVERSAL IN BINARY TREEE
    node * levelOrderTraversal( node * root){
        queue<node *> q;
        q.push(root);
        q.push(NULL);   // SEPERATOR
        while (!q.empty()){
            node * temp = q.front();
            q.pop();

            if (temp==NULL){    // PURANA LEVEL COMPLETE HO CHUKA H AB NEXT KE LIVE SEPARTOR CHAHIYE 
                cout<<endl;
                if (!q.empty()){    // QUEUE STILL HAVE SOME CHILD
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";

            if ( temp->left){
                q.push(temp->left);
            }
        
        if (temp->right){
            q.push(temp->right);
        }
        }
        }
    }
        // INORDER TRAVERSAL
    node * inorder ( node * root){    // L-N-R
        if ( root ==NULL){
            return;
        }
        inorder( root->left);  // LEFT
        cout<<root->data<<" "; // NODE PRINT
        inorder( root->right); // RIGHT

    }
            // PREORDER TRAVERSAL 
    node * preorder ( node * root){    // N-L-R
        if ( root ==NULL){
            return root;
        }
        
        cout<<root->data<<" "; // NODE PRINT
         preorder( root->left);  // LEFT
        preorder( root->right); // RIGHT

    }
            // POSTORDER TRAVERSAL
     node * postorder ( node * root){    // N-L-R
        if ( root ==NULL){
            return;
        }
        
       
         postorder( root->left);  // LEFT
        postorder( root->right); // RIGHT
         cout<<root->data<<" "; // NODE PRINT

    }

     void bildingfromlevelorder(  node * &root){
        queue<node *>q;
        cout<<" enter the data for root"<<" ";
        int data;
        cin>>data;
        root= new node (data );
        while ( !q.empty()){
            node * temp= q.front();
            q.pop();

            cout<<" enter the left side data for  "<< temp->data<<" ";
            int leftdata;
            cin>>leftdata;
            if (leftdata!=-1){
                temp->left=new node(leftdata);
                q.push(temp->left);
            }
            cout<<" enter the right side data for "<< temp->data<<" ";
            int rightdata;
            cin>>rightdata;
            if (rightdata!=-1){
                temp->left=new node(rightdata);
                q.push(temp->right);
            }

        }
     }
     void inorder ( node * &root, int &count){    
        if ( root ==NULL){
            return;
        }
        inorder( root->left , count);  

            // CONDITION TO CHECK LEAF NODES IN A TREE->
        if ( root->left==NULL && root->right==NULL){
            count++;
        } 
        inorder( root->right, count); 

    }
int noOfLeafNodes(node *root){   // TP FIND LEAF NODES
    int count=0;
    inorder(root,count);
    return count;
}
int height( node* root){   // CALCULATE HEIGHT OF THE TREE
        if ( root  ==NULL){
            return 0;
        }
        int  h1= height(root->left);
         int h2= height(root->right);
        int ans = max ( h1,h2)+1;
        return ans;
        
    }
 
int main(){
    node * root =NULL;

    root = buildtree(root);
    levelOrderTraversal(root);
    inorder(root);
}
