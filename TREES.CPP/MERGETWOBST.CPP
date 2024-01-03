#include <iostream>
using namespace std;
#include <vector>
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

/*void inorder(TreeNode *root, vector<int> &in)      // STEP->FIND INORDER OF BOTH TREE
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
vector<int> merge(vector<int> &a, vector<int> &b)    // MERGE THEIR SORTED AARRAY USING MERGE SORT
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            a[k++] = a[i];
            i++;
        }
        else
        {
            a[k++] = b[j];
            j++;
        }
    }
    while (i < a.size())
    {
        a[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        a[k++] = b[j];
        j++;
    }
    return ans;
}
TreeNode * inordertobst( int s, int e, vector<int> &in)
// CREATE AN BST USING MERGED ARRAY
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(in[mid]);
    root->left = inordertobst(s, mid - 1, in);
    root->right = inordertobst(mid + 1, e, in);
    return root;
}
int main(){

TreeNode * mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergearray = merge(bst1, bst2);
    int s = 0;
    int e = mergearray.size() - 1;
    return inordertobst(s, e, mergearray);
}
}*/



// APPROACH 2-> BETTER APPROCH OF O(H1+H2) AND SPACE O(H)->
void inorder(TreeNode *root, vector<int> &in){
    if ( root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder( root->right,in);
}

int countnodes(TreeNode*head){
    int cnt=0;
    TreeNode* temp=head;
    while (temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;

}
TreeNode * inordertobst( int s, int e, vector<int> &in)  // INORDER T0 BST->
// CREATE AN BST USING MERGED ARRAY
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(in[mid]);
    root->left = inordertobst(s, mid-1, in);
    root->right = inordertobst(mid+1, e, in);
    return root;
}
void convertintosortedDLL(TreeNode *root,TreeNode * &head ){  //BST INTO DOUBLY LL
    // coverted bst into doubly linked list
    if ( root==NULL){
        return ;
    }
    convertintosortedDLL(root->right,head);
    root->right=head;
    if (head != NULL) {
        head->left = NULL;
    }
    head=root;
    convertintosortedDLL(root->left,head);
}
TreeNode* mergelinkedlist(TreeNode* head1,TreeNode*head2){  // MERGE TWO  SORTED LINKED LIST
    TreeNode* head=NULL;
    TreeNode* tail=NULL;
    while (head1!=NULL && head2!=NULL){
        if (head1->data<head2->data){
            if (head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;

            }
            else{
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
            }
        }
        else{
                if (head==NULL){
                    head=head2;
                    tail=head2;
                    head1=head2->right;
                }
                else{
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;

                }
        }
    }
    while (head1!=NULL){
                     tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;

    }
    while (head2!=NULL){
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
        
    }
    return head;
}
TreeNode* sortedLLtoBST( TreeNode*&head,int n){    // LL INTO BST
    // base case
    if ( n<=0 || head==NULL){
        return NULL;
    }
    TreeNode* left = sortedLLtoBST(head,n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}


TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)   //MAIN FN->
{
   
    TreeNode* head1= NULL;
    convertintosortedDLL(root1,head1);
    head1->left=NULL;

    TreeNode* head2= NULL;
    convertintosortedDLL(root2,head1);
    head2->left=NULL;
    // merge sorted linked list->
     TreeNode* head=mergeBST(head1, head2);
    // covert sorted ll into bst->
    return sortedLLtoBST(head, countnodes(head));
}