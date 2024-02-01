
/*
Code
Testcase
Testcase
Test Result
123. Best Time to Buy and Sell Stock III
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.*/



// recursion->
class Solution {
public:
    int solve( int index, int buy , vector<int>& prices,int limit){
        if (index==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        int profit=0;
        if (buy){
            int buykaro=-prices[index]+solve(index+1,0,prices,limit);
            int skipkaro=0+solve(index+1,1,prices,limit);
            profit=max(buykaro,skipkaro);
        }
        else{
            int sellkro=prices[index]+solve(index+1,1,prices,limit-1);
            int skipkro=0+solve(index+1,0,prices,limit);
            profit=max(sellkro,skipkro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
    }
};

// recursion + memoization->
class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int limit,vector<vector<vector<int>>>&dp) {
        if (index == prices.size()) {
            return 0;
        }
        if (limit == 0) {
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solve(index + 1, 0, prices, limit,dp);
            int skipkaro = 0 + solve(index + 1, 1, prices, limit,dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkro =
                prices[index] + solve(index + 1, 1, prices, limit - 1,dp);
            int skipkro = 0 + solve(index + 1, 0, prices, limit,dp);
            profit = max(sellkro, skipkro);
        }
        return dp[index][buy][limit]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
         return solve(0, 1, prices, 2,dp);
          }
};

// tabulation->
class Solution {
public:
    int solve(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buykaro = -prices[index] + dp[index + 1][0][limit];
                        int skipkaro = 0 + dp[index + 1][1][limit];
                        profit = max(buykaro, skipkaro);
                    } 
                    else
                     {
                        int sellkro =prices[index] + dp[index + 1][1][limit - 1];
                        int skipkro = 0 + dp[index + 1][0][limit];
                        profit = max(sellkro, skipkro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) { return solve(prices); }
};

// space optimization->
class Solution {
public:
    int solve(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buykaro = -prices[index] + next[0][limit];
                        int skipkaro = 0 + next[1][limit];
                        profit = max(buykaro, skipkaro);
                    } 
                    else
                     {
                        int sellkro =prices[index] + next[1][limit - 1];
                        int skipkro = 0 + next[0][limit];
                        profit = max(sellkro, skipkro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) { return solve(prices); }
};