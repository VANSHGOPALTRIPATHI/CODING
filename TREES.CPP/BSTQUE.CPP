#include<iostream>
using namespace std;
class BinaryTreeNode {
    
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    bool isBST(BinaryTreeNode * &root, int min, int max ){    // VALID BST OR NOT 
    if ( root==NULL){
        return true;
    }
    if ( root->data> min && root->data< max){
        bool left = isBST( root->left, min ,root->data);
        bool right=isBST ( root->right, root->data, max);
        return left && right;
    }
     else {
        return false;
    }

    // FIND KTH ELEMENT

    int solve(BinaryTreeNode* root, int &i , int k ){     
     if ( root == NULL){
         return -1;
     }
     //L
     int left = solve ( root->left , i, k );
     if ( left!=-1){
         return left;
     }
     //N 
     i++;
     if ( i==k){
     return root->data;
     }

     //R
     int right = solve ( root->right,i,k);

 }

 // predecessor ans successor ->
 
 pair<int, int> predecessorSuccessor(TreeNode* root, int key){

    TreeNode* temp= root;
    int pred=-1;
    int succ=-1;
     while( temp->data!=key){
       if (temp->data > key) {
         succ = temp->data;
         temp = temp->left;
       }

       else {
         pred = temp->data;
         temp = temp->right;
       }
     }

    // pred
    TreeNode* lefttree=temp->left;
    while ( lefttree != NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }
    //succ 
    TreeNode* righttree=temp->right;
    while ( righttree != NULL){
        succ= righttree->data;
        righttree=righttree->left;
    }
    pair<int,int> ans=make_pair(pred, succ);
    return ans;




}
// FLATTEN A BST->
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderval;
    // store inoder sorted values->

    inorder( root,inorderval);
    int n = inorderval.size();

    TreeNode<int>* newroot=new TreeNode<int>(inorderval[0]);

    TreeNode<int>* curr=newroot;

    for ( int i=1;i<n; i++){
        TreeNode<int>*temp= new TreeNode<int>(inorderval[i]);
        
        curr->left=NULL;
        curr->right=temp;
        curr=temp;

    }
    curr->left=NULL;
    curr->right=NULL;

    return newroot;

}



int main(){
    BinaryTreeNode* root;


bool validateBST(BinaryTreeNode *root ) ;
    // Write your code here
    int i=0;
     bool ans = isBST( root, -100000, +100000);
    
}
