#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {       // find kth smallest elemenet;
        //code 
        // step-1->
        priority_queue<int> pq;
        for ( int i=0; i<k ;i++){
            pq.push(arr[i]);
        }
        //step->2 remaining elements
        for (int i=k; i<=r;i++){
            if (arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // step->3 answer is top heap element
        int ans = pq.top();
        return ans;
    }};
    
    
    
  //--------------------------------------------------------------------------------------------------------------  
    // Q2-> CHECK WHETEHER A TREE IS A HEAP->
class Node {
  public:
  int data;
  Node *left;
  Node* right;
    bool isHeap(struct Node* root) {
        // code here
        int index=0;
        int totalcount=countnodes(root);
        if ( isCBT(root,index, totalcount) && ismaxorder(root)){
            return true;
        }
        else{
            return false;
        }
    }
};
int countnodes( struct Node* root){
    if (root==NULL){
        return 0;
    }
    int ans = 1+ countnodes(root->left)+countnodes(root->right);
    return ans;
    
}
bool isCBT( struct Node* root, int i , int count){
    if (root==NULL){
        return true;
    }
    if ( i >= count){
        return false;
    }
    else {
        bool left= isCBT(root->left, 2*i+1,count);
        bool right= isCBT(root->right,2*i+2,count);
        return (left && right);
    }
}
bool ismaxorder(struct Node* root){
    //leaf node 
    if (root->left==NULL && root->right==NULL){
        return true;
        
    }
    if (root->right==NULL){
        return ( root->data > root->left->data);
    }
    else {
        bool left=ismaxorder(root->left);
        
        bool right= ismaxorder(root->right);
        
        if (left && right && (root->data > root->left->data && root->data >  root->right->data)){
            return true;
        }
        else{
            return false;
        }
    }
}
//------------------------------------------------------------------------------------------------------------------
// MERGE TWO HEAPS->>>>>
class Solution{
    public:
    void heapify( vector<int>&arr, int i , int n){    // HEAPIFY ALGORITHM
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if ( left<n &&  arr[largest]<arr[left]){
            largest=left; 
        }
         if ( right<n &&  arr[largest]<arr[right]){
            largest=right;
        }

        if (largest!=i){

            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
     }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        // MERGE TWO VECTOR
        vector<int> ans ;
        
        for (auto i:a){
            ans.push_back(i);
            
        }
        for (auto i:b){
            ans.push_back(i);
        }
        // build a heap from vector
        int size= ans.size();
        for( int i=size/2-1; i>=0 ;i--){
        heapify(ans,i,size);
    }
    return ans;
    }
};
//---------------------------------------------------------------------------------------------------------------
// MINIMUM COST OF ROPES 
    long long minCost(long long arr[], long long n) {
        // Your code here
        // creating min heap->
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        long long cost=0;
        for (int i=0; i<n ;i++){
            pq.push(arr[i]);       
            /* evry time taking two smallest element and adding and storing it in sum and sending sum and adding sum in cost ad returning cost ss  answer*/
        }
        while (pq.size()>1){
            long long a= pq.top();
            pq.pop();
            
            long long b= pq.top();
            pq.pop();
            long long sum= a+b;
            
            cost=cost+sum;
            pq.push(sum);
        }
    
    return cost;
    }
    //----------------------------------------------------------------------------------------------------------------
	// KTH largest subarray sum ->
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sumstore;
	for ( int i=0 ; i< arr.size(); i++){
		int sum=0;
		for ( int j=i ; j<arr.size();j++){
			sum+=arr[j];
			sumstore.push_back(sum);
		}
        // from these two loops we have created the a vector of sum of subarray into sumstore vector
	}
	sort(sumstore.begin(),sumstore.end());  // using sort function by including alogorithm header
	return sumstore[sumstore.size()-k];   // returning answer;
}

// APROACH 2->
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int,vector<int>, greater<int>>minheap;
	for ( int i=0 ; i< arr.size(); i++){
		int sum=0;
		for ( int j=i ; j<arr.size();j++){
			sum+=arr[j];
			if (minheap.size()<k){
				minheap.push(sum);
			}
			else {
				if (sum>minheap.top()){
					minheap.pop();
					minheap.push(sum);
				}
			}
		}
	}
	return minheap.top();
}
//------------------------------------------------------------------------------------------------------------------

                            // MOST IMPORTANT QUESTIONS ->>>>
// smallest range in kth lists->>>> which inlucde atleast one element from each list;
#include<limits.h>
#include<queue>
class node{
    public:
    int data;
    int row;
    int col;

    node(int dat,int row, int column) {
      data = dat;
      row = row;
      col = column;
    }
};
class compare{
    public:
    bool operator()(node*a , node*b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node*, vector<node*>,compare>minheap;

    for( int i=0 ;i<k ;i++){
        int element = a[i][0];
        mini=min(mini,element);
        maxi= max(maxi,element);
        minheap.push( new node(element,i,0));
    }
    int start=mini, end =maxi;
    while (!minheap.empty()){
        node *temp= minheap.top();
        minheap.pop();
        mini=temp->data;
    
    if (maxi-mini < end-start){
        start=mini;
        end=maxi;
    }
    if (temp->col+1 < n){
        maxi=max (maxi,a[temp->row][temp->col+1]);
        minheap.push( new node (a[temp->row][temp->col+1],temp->row,temp->col+1));
    } 
    else {
        break;
    }
    }
    return (end - start + 1);

}