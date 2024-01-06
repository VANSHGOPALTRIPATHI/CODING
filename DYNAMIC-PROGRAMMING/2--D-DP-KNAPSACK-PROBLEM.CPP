/*Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3*/

// code =>

//recursion->
#include <bits/stdc++.h> 

int solve (vector<int> &weight, vector<int> &value, int index, int capacity ){
	// n-> last index , capacity->max weight
	if ( index==0){
		if (weight[0]<=capacity){
				return value[0];
		}
		else{
			return 0; 
		}
	}
	int include=0;
	if ( weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	}
	int exclude=0+solve(weight,value,index-1,capacity);
	int ans = max(include,exclude);
	return ans;

}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>dp()
	return solve(weight,value,n-1,maxWeight);
}

//***********************************************************************************************************

// recursion+memoization->>>

#include <bits/stdc++.h> 

int solve (vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>>&dp ){
	// n-> last index , capacity->max weight
	if ( index==0){
		if (weight[0]<=capacity){
				return value[0];
		}
		else{
			return 0; 
		}
	}
	if (dp[index][capacity]!=-1){
		return dp[index][capacity];
	}

	int include=0;
	if ( weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
	}
	int exclude=0+solve(weight,value,index-1,capacity,dp);
	dp[index][capacity] = max(include,exclude);
	return dp[index][capacity];

}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// 2d vector -> 2d dp 2 states are changing
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}

//*************************************************************************************************************



// tabulaition->

#include <bits/stdc++.h>

int solvetabualtion(vector<int> &weight, vector<int> &value, int n,
                    int capacity) {
  // n-> last index , capacity->max weight
  // step-1->infitaializing vector->
  vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

  // step->  2 anaylyzing base  case->

  for (int w = weight[0]; w <= capacity; w++) {
    if (weight[0] <= capacity) {
      dp[0][w] = value[0];
    } else {
      dp[0][w] = 0;
    }
  }
  for (int index = 1; index < n; index++) {
    for (int w = 0; w <= capacity; w++) {
      int include = 0;
      if (weight[index] <= w) {
        include = value[index] + dp[index - 1][w - weight[index]];
      }
      int exclude = 0 + dp[index - 1][w];
      dp[index][w] = max(exclude, include);
    }
  }

  return dp[n - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  // 2d vector -> 2d dp 2 states are changing

  int ans= solvetabualtion(weight, value, n, maxWeight);
  return ans ;
}

//***************************************************************************************************************

// space optimization->

#include <bits/stdc++.h>

int solvetabualtion(vector<int> &weight, vector<int> &value, int n,
                    int capacity) {
  // n-> last index , capacity->max weight
  // step-1->infitaializing vector->
  vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
  vector<int>prev(capacity + 1, 0);
  vector<int>curr(capacity + 1, 0);


  // step->  2 anaylyzing base  case->

  for (int w = weight[0]; w <= capacity; w++) {
    if (weight[0] <= capacity) {
      prev[w] = value[0];
    } else {
      prev[w] = 0;
    }
  }
  for (int index = 1; index < n; index++) {
    for (int w = 0; w <= capacity; w++) {
      int include = 0;
      if (weight[index] <= w) {
        include = value[index] + prev[w - weight[index]];
      }
      int exclude = 0 + prev[w];
      curr[w] = max(exclude, include);
    }
	prev=curr;
  }

  return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  // 2d vector -> 2d dp 2 states are changing

  int ans= solvetabualtion(weight, value, n , maxWeight);
  return ans ;
}

//*****************************************************************************************************