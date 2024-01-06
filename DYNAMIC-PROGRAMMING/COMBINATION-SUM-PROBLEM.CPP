//https://www.codingninjas.com/studio/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/*Problem statement
You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.

Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

Input is given such that the answer will fit in a 32-bit integer. For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.*/

// recursion soln->
//****************************************************************************
#include <bits/stdc++.h> 
int solverecursion(vector<int> &num, int tar){
    if (tar==0){
        return 1;
    }
    if (tar<0){
        return 0;
    }
    int ans=0;

    for (int i=0 ;i<num.size();i++){
         ans += solverecursion(num,tar-num[i]);
    }
    return ans;
}


int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solverecursion(num,  tar);
}
//****************************************************************************
// recurison+memoization->

#include <bits/stdc++.h> 
int rec__memo(vector<int> &num, int x,vector<int>&dp) {
  if (x == 0) {
    return 1;
  }
  if (x < 0) {
    return 0;
  }
  int ans = 0;

  if (dp[x]!=-1){
    return dp[x];
  }

  for (int i = 0; i < num.size(); i++) {
    ans += rec__memo(num, x - num[i], dp);
  }
  dp[x]=ans;

  return dp[x];
}


int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int>dp(tar+1,-1);
    return solverecursion(num,  tar,dp);
}
//****************************************************************************
// tabulation->

#include <bits/stdc++.h> 
int solvetabular(vector<int> &num, int tar) {

  vector<int> dp(tar + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= tar; i++) {
    // i am trying to get all soln->...
    for (int j = 0; j < num.size(); j++) {
        if(i-num[j]>=0){
              dp[i] += dp[i-num[j]];
        }
    
    }
  }
  return dp[tar];
}

  
int findWays(vector<int> &num, int tar)
{
    return solvetabular(num,  tar);
}

//****************************************************************************

//space optimization->

 // SAME SPACE WILL BE TAKEN SO MORE OPTIMIZE CAN NOT BE DONE AS IT DEPEND UPON dp[i],1+dp[i-num[j]] CAN NOT BE DECLARED AS VARIABLE