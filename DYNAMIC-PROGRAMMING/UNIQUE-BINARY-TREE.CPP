/*Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19*/

// RECURISON->
class Solution {
public:
    int numTrees(int n) {
        int ans =0 ;
        if ( n<=1){
            return 1;
        }

        for ( int i=1 ;i <=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};
// memoization->
class Solution {
public:

    int solve(int n, vector<int>&dp  ){
     int ans =0 ;
    if ( n<=1){
            return 1;
        }
    if(dp[n] !=-1){
         return dp[n];
        }

        for ( int i=1 ;i <=n;i++){
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        dp[n]= ans;
        return dp[n];
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return  solve(n,dp);

    }
};

// bottom up->
class Solution {
public:
    int solve(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) { return solve(n); }
};