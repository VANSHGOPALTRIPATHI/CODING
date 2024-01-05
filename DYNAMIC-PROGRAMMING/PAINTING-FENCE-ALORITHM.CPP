/*Problem statement
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011*/

// RECURSIVE SOLUTION ->
#define MOD 1000000007
#include <bits/stdc++.h>

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }


int solve (int n,int k){
     if (n==1){
        return k;
    }
    if (n==2){
        return add(k,mul(k,k-1));
    }
    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans ;
}

int numberOfWays(int n, int k) {
    // Write your code here.
   return solve (n,k);

}

//************************************************************************************************************


// RECURISVE + MEMOIZATION ->

#define MOD 1000000007
#include <bits/stdc++.h>

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) *1LL* (b%MOD)) % MOD; }


int solvememo (int n,int k,vector<int>&dp){
     if (n==1){
        return k;
    }
    if (n==2){
        return add(k,mul(k,k-1));
    }
    if ( dp[n]!=-1){
        return dp[n];
    }
    dp[n] = add(mul(solvememo(n-2,k,dp),k-1),mul(solvememo(n-1,k,dp),k-1));
    return dp[n] ;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);
   return solvememo (n,k,dp);

}
//***************************************************************************************************************************

// solve tabulation->
int solvetabu( int n,int k){
        vector<int>dp(n+1,-1);
            dp[1]=k;
            dp[2]=add(k,mul(k,k-1));

            for (int i=3;i<=n;i++){
                dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
            }
            return dp[n];
        
    }

int numberOfWays(int n, int k) {
  return solvetabu(n, k);

}
//******************************************************************************************************************************

// space optimixation->

#define MOD 1000000007
#include <bits/stdc++.h>

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }

int spaceoptimization(int n, int k) {

  int prev2 = k;
  int prev1 = add(k, mul(k, k - 1));

  for (int i = 3; i <= n; i++) {
    int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));
    prev2=prev1;
    prev1=ans;
  }
  return prev1;
}

int numberOfWays(int n, int k) {
  return spaceoptimization(n,k);
}

