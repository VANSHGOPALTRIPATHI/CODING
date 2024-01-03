#include<iostream>
using namespace std;
#include<climits>;
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };



class info {

    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};
info solve (TreeNode* root, int &ans){
    if (root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve (root->left, ans);
    info right=solve (root->right,ans);
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);

    if ( left.isbst && right.isbst && (root->data > left.maxi && root->data<right.mini)){
        currNode.isbst=true;
    }
    else {
        currNode.isbst=false;
    }
    if (currNode.isbst){
        ans= max( ans, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode * root){
    int maxsize =0;
    info temp= solve ( root, maxsize);
    return maxsize;
}