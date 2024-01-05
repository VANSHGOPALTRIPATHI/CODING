/*Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).*/



// recursive solution ->> TLE ->

#define MOD 100000007
long long int countDerangements(int n) {
  // Write your code here.
  // base case
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  int ans =
      (((n - 1) % MOD) *
       ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) %
       MOD);

       return ans;
}

//***************************************************************************************************

// recursion + memoization=>>

#define MOD 1000000007
#include <vector>

long long int solvememoization(int n, vector<long long int> &dp) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  if (dp[n] != -1) {
    return dp[n];
  }

    dp[n] = (((n - 1) % MOD) *
                         ((solvememoization(n - 1, dp) % MOD) +
                          (solvememoization(n - 2, dp) % MOD)) %
                         MOD);

  return dp[n];
}

long long int countDerangements(int n) {
  // Write your code here.
  // base case
  vector<long long int> dp(n+1, -1);
  return solvememoization(n, dp);
  
}
//**************************************************************************************************

// tabulation

#define MOD 1000000007
#include <vector>

long long int solvetabulation( int n){
  vector< long long int> dp(n+1,0);
  dp[1]=0;
  dp[2]=1;

  for ( int i=3 ;i<=n ;i++){
    long long int first= dp[i-1]%MOD;
    long long int second= dp[i-2]%MOD;
    long long int third= (i-1)%MOD;
    long long int ans=(third*(first+second))%MOD;

  dp[i]=ans;
  }
  return dp[n];
  
}

long long int countDerangements(int n) {
  // Write your code here.
  // base case
  return solvetabulation(n);
  
}

//*************************************************************************************************


// space optimization   ->>


#define MOD 1000000007
#include <vector>

long long int solvetabulation( int n){
  vector< long long int> dp(n+1,0);
  long long int prev2=0;
  long long int prev1=1;

  for ( int i=3 ;i<=n ;i++){
    long long int first= prev1%MOD;
    long long int second= prev2%MOD;
    long long int third= (i-1)%MOD;
    long long int ans=(third*(first+second))%MOD;

    dp[i]=ans;
    prev2=prev1;
    prev1=ans;
  }
  return prev1;
  
}

long long int countDerangements(int n) {
  // Write your code here.
  // base case
  return solvetabulation(n);
  
}

