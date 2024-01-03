#include<iostream> 
using namespace std;
#include<queue>

class node {
    public:
    int data;
    node * left;
    node * right;

    public:
    node ( int value){
        this->data= value;
        this->left=NULL;
        this ->right=NULL;
    }
};
node * insertTOBST( node * root, int d){
    if ( root==NULL){
        root= new node(d);
        return root;
    }
    if (d>root->data){
        root->right=insertTOBST( root->right, d);
    }
    else{
        root->left= insertTOBST( root->left,d);
    }
    return root;

}
bool searchInBST(node *root, int x) {    // searching in a binary tree;
    // Write your code here.  
    if ( root==NULL){
        return false;
    }
    if ( root->data ==x){
        return true;
    }
    if ( root->data>x){
        return searchInBST(root->left,x);
    }
    else {
        return searchInBST(root->right,x);
    }
}

node* takeinput( node * &root){
    int data;
    cout<<" enter data"<<" ";
    while( data!=-1){
        insertTOBST( root,data);
        cin>>data;
    }

}
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
    node * minimumvalue( node * &root){    // MINIMUM VALUE OF  BST
        node * temp=root;
        while ( temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
        node * maximumvalue( node * &root){     // MAXIMUM VALUE OF A BST
        node * temp=root;
        while ( temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    node * deletefromBSt( node * root, int x){      // DELETING A NODE FROM BST
                                                    // VERY IMPORTANT UNDERSTAND  IT  PROPERLY !!!!!

        if ( root==NULL){
            return root;
        }
        if (root->data==x){
            // 0 child
            if ( root->left ==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            // 1 child
            // left child
            if ( root->left!=NULL  && root->right==NULL){
                node * temp= root->left;
                delete root;
                return temp;
            }
            //right child 
            if ( root->left==NULL  && root->right!=NULL){
                node * temp= root->right;
                delete root;
                return temp;
            }

            // 2 child
            if ( root->left!=NULL && root->right !=NULL){
                int mini=minimumvalue(root->right)->data;
                root->data=mini;
                root->right=deletefromBSt( root->right, mini);
                return root;
            }



        }
        else if ( root->data> x){
            root->left=deletefromBSt(root->left,x);
            return root;
        }
        else {
            root->right= deletefromBSt( root->right,x);
            return root;
        }
            }
int main(){
    node * root= NULL;
    int data;
    cout<<" enter the data for BST"<<endl;
    cin>>data;
    takeinput( root);
    cout<<" printing the BST";
    levelOrderTraversal(root);
}
