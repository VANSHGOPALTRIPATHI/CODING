/*1388. Pizza With 3n Slices
Hard
Topics
Companies
Hint
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:

*/

// recurison->
class Solution {
public:

    int solve ( int index,vector<int>& slices,int n){
        if ( n==0 || index>slices.size()){
            return 0;
        }

        int take = slices[index]+solve ( index+2,slices,n-1);
        int nottake =0+solve ( index+1,slices,n);

        return max(take,nottake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        int case1= solve(0,slices,k/3); 
        int case2= solve(1,slices,k/3); 

        return max(case1,case2);
    }
};

// recurison + memoization->

#include <bits/stdc++.h>

 int solve ( int index,int end,vector<int>& arr,int n,vector<vector<int>>&dp){
        if ( n==0 || index>end){
            return 0;
        }
        if (dp[index][n]!=-1){
            return dp[index][n];
        }

        int take = arr[index]+solve ( index+2,end,arr,n-1,dp);
        int nottake =0+solve ( index+1,end,arr,n,dp);

        dp[index][n]= max(take,nottake);
        return dp[index][n];
    }

int pizzaSharing(int n, vector<int> &arr)
{
    // Write your code here.
     int k = arr.size();
     vector<vector<int>>dp1(k,vector<int>(k,-1));

        int case1= solve(0,k-2,arr,k/3,dp1); 
        vector<vector<int>>dp2(k,vector<int>(k,-1));
        int case2= solve(1,k-1,arr,k/3,dp2); 

        return max(case1,case2);
}


// tabulation->

#include <bits/stdc++.h>

int solvetab(vector<int> &arr) {
  int k = arr.size();
  vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
  vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

  for (int index = k - 2; index >= 0; index--) {
    for (int n = 1; n <= k / 3; n++) {
      int take = arr[index] + dp1[index + 2][n - 1];
      int nottake = 0 + dp1[index + 1][n];

      dp1[index][n] = max(take, nottake);
    }
  }
int case1 = dp1[0][k / 3];

    for (int index = k - 1; index >= 1; index--) {
      for (int n = 1; n <= k / 3; n++) {
        int take = arr[index] + dp2[index + 2][n - 1];
        int nottake = 0 + dp2[index + 1][n];

        dp2[index][n] = max(take, nottake);

      }
    }
    int case2= dp2[1][k/3];

    return max(case1,case2);
             }

      int pizzaSharing(int n, vector<int> &arr) {
        // Write your code here.
        return solvetab(arr);
      }

      // space optimization-->>

      



