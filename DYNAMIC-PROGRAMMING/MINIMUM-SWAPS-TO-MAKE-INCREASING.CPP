
/*801. Minimum Swaps To Make Sequences Increasing
Hard
Topics
Companies
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.*/

// RECURSIVE SOLUTION ->

class Solution {
public:

int solve (vector<int>& nums1, vector<int>& nums2,int index ,bool swapped ){

    if ( index == nums1.size()){
        return 0;
    }
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    // catch 
    if ( swapped){
        swap(prev1,prev2);
    }
    int ans =INT_MAX ;
    // no swapped
    if ( nums1[index]>prev1 && nums2[index]>prev2){
        ans = solve ( nums1 ,nums2 , index+1, 0);
    }
    // swap
    if ( nums1[index]>prev2 && nums2[index]>prev1){
        ans = min ( ans ,1+ solve ( nums1,nums2,index+1,1));
    }

    return ans ;


    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped =0;
        return solve ( nums1,nums2,1,swapped);
        
    }
};

// RECURSION + MEMOIZATION->

class Solution {
public:

int solve (vector<int>& nums1, vector<int>& nums2,int index ,bool swapped ,vector<vector<int>>&dp){

    if ( index == nums1.size()){
        return 0;
    }
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    // catch 
    if ( swapped){
        swap(prev1,prev2);
    }
    if ( dp[index][swapped]!=-1){
        return dp[index][swapped];
    }
    int ans =INT_MAX ;
    // no swapped
    if ( nums1[index]>prev1 && nums2[index]>prev2){
        ans = solve ( nums1 ,nums2 , index+1, 0,dp);
    }
    // swap
    if ( nums1[index]>prev2 && nums2[index]>prev1){
        ans = min ( ans ,1+ solve ( nums1,nums2,index+1,1,dp));
    }

    return dp[index][swapped]= ans ;


    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped =0;
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
    
        return solve ( nums1,nums2,1,swapped,dp);
        
    }
};

// tabulation->
class Solution {
public:
    int tabulation(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
        
        
        
        for ( int index = nums1.size()-1; index>=1 ;index--){
            for ( int swapped=1 ; swapped>=0 ;swapped--){
                int ans =INT_MAX ;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch 
                if (swapped){
                    swap(prev1,prev2);
                }
                // no swapped
                if ( nums1[index]>prev1 && nums2[index]>prev2){
                    ans = dp[index+1][0];
                }
                // swap
                if ( nums1[index]>prev2 && nums2[index]>prev1){
                    ans = min( ans ,1+ dp[index+1][1]);
                }

                dp[index][swapped]= ans ;
                    }
                }
                return dp[1][0];
                }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return tabulation( nums1,nums2);
        
    }
};

// space optimization ->

class Solution {
public:
    int tabulation(vector<int>& nums1, vector<int>& nums2) {

        int swaper=0;
        int noswap=0;
        int currswap=0;
        int currnoswap=0;

        for (int index = nums1.size() - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped) {
                    swap(prev1, prev2);
                }
                // no swapped
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = noswap;
                }
                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + swaper);
                }

                if ( swapped){
                    currswap=ans;
                }
                else{
                    currnoswap=ans;
                }
            }
            swaper=currswap;
            noswap=currnoswap;
        }
        return min(swaper,noswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return tabulation(nums1, nums2);
    }
};

