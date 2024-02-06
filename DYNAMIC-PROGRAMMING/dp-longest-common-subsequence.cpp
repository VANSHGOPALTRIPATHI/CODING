/*1143. Longest Common Subsequence
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.*/

// reucriosn->

class Solution {
public:

    int solve ( string &text1,string &text2,int i,int j){
        if (i==text1.length()){
            return 0;
        }
        if(j==text2.length()){
            return 0;
        }
        int ans=0;
        if ( text1[i]==text2[j]){
            ans= 1+solve(text1,text2,i+1,j+1);
        }
        else{
            ans = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2){
        return solve(text1,text2,0,0);
    }
};

// dp->
class Solution {
public:

    int solve ( string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        if (i==text1.length()){
            return 0;
        }
        if(j==text2.length()){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if ( text1[i]==text2[j]){
            ans= 1+solve(text1,text2,i+1,j+1,dp);
        }
        else{
            ans = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2){
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0,dp);
    }
};

// tabulation->
class Solution {
public:

    
    int bottomup(string&text1,string&text2){
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for ( int i=n-1;i>=0;i--){
            for ( int j=m-1;j>=0;j--){
                int ans=0;
                 if ( text1[i]==text2[j]){
                    ans= 1+dp[i+1][j+1];
        }
                else{
                        ans = max(dp[i+1][j],dp[i][j+1]);
        }
         dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2){
     
        return bottomup(text1,text2);
    }
}; 

// space optimizar=tion-.
class Solution {
public:

    
    int space(string&text1,string&text2){
        int n = text1.size();
        int m = text2.size();
        vector<int>curr(m+1);
        vector<int>next(m+1);
        for ( int i=n-1;i>=0;i--){
            for ( int j=m-1;j>=0;j--){
                int ans=0;
                 if ( text1[i]==text2[j]){
                    ans= 1+next[j+1];
        }
                else{
                        ans = max(next[j],curr[j+1]);
        }
         curr[j] = ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2){
     
        return space(text1,text2);
    }
};