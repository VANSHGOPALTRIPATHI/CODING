// simple resursion approach->

#include <bits/stdc++.h> 
int solverecursion(vector<int> &num, int x){
    if (x==0){
        return 0;
    }
    if (x<0){
        return INT_MAX;
    }
    int mini=INT_MAX;

    for (int i=0 ;i<num.size();i++){
        int ans = solverecursion(num,x-num[i]);
        if (ans!=INT_MAX){
            int mini= min(mini,1+ans);
        }
        

    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans = solverecursion(num,x);
    if (ans==INT_MAX)
        return -1;
}
//***************************************************************************************************************************************

// top down approach->

#include <bits/stdc++.h>
int solverecursion(vector<int> &num, int x,vector<int>&dp) {
  if (x == 0) {
    return 0;
  }
  if (x < 0) {
    return INT_MAX;
  }
  int mini = INT_MAX;

  if (dp[x]!=-1){
    return dp[x];
  }

  for (int i = 0; i < num.size(); i++) {
    int ans = solverecursion(num, x - num[i],dp);
    if (ans != INT_MAX) {
      mini = min(mini, 1 + ans);
    }
  }
  dp[x] = mini;
  
  return mini;
}
int minimumElements(vector<int> &num, int x) {
  vector<int> dp(x,-1);
  int ans = solverecursion(num, x,dp);
  if (ans == INT_MAX)
    return -1;
  else{
      return ans;
  }
 
}

//*****************************************************************************************************************************************

//bottom-up approach->  tabular->

#include <bits/stdc++.h>

int solvetabular(vector<int> &num, int x) {

  vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    // i am trying to get all soln->...
    for (int j = 0; j < num.size(); j++) {
      if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
          dp[i]=min(dp[i],1+dp[i-num[j]]);
      }
    }
  }
  if (dp[x] == INT_MAX) {
    return -1;
  } else {
    return dp[x];
  }
}
int minimumElements(vector<int> &num, int x) { 
  return solvetabular(num, x); 
  }

// tc->O(n*x);
// S-C ->O(X);

  //************************************************************************************************************************************

  // space optimization approach->>

  // SAME SPACE WILL BE TAKEN SO MORE OPTIMIZE CAN NOT BE DONE AS IT DEPEND UPON dp[i],1+dp[i-num[j]] CAN NOT BE DECLARED AS VARIABLE

