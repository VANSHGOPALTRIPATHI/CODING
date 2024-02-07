/*72. Edit Distance
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')*/

// recursion->

class Solution {
public:

    int solve ( string&a,string&b,int i,int j){
        if (i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }
        int ans=0;
        if( a[i]==b[j]){
            ans=solve(a,b,i+1,j+1);
        }
        else{
            // insert->
            int insertans=1+solve(a,b,i,j+1);
            // remove->
            int deleteans=1+solve(a,b,i+1,j);
            // replace->
            int replaceans=1+solve(a,b,i+1,j+1);
            ans=min(insertans,min(deleteans,replaceans));
        }
        return ans;

    }

    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};

// dp->

class Solution {
public:

    int solve ( string&a,string&b,int i,int j,vector<vector<int>>&dp){
        if (i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if( a[i]==b[j]){
            ans=solve(a,b,i+1,j+1,dp);
        }
        else{
            // insert->
            int insertans=1+solve(a,b,i,j+1,dp);
            // remove->
            int deleteans=1+solve(a,b,i+1,j,dp);
            // replace->
            int replaceans=1+solve(a,b,i+1,j+1,dp);
            ans=min(insertans,min(deleteans,replaceans));
        }
        return  dp[i][j]=ans;

    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};

// tabulation->
class Solution {
public:

    int tabulation(string&a,string&b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for (int j=0;j<b.length();j++){
            dp[a.length()][j]=b.length()-j;
        }
         for (int i=0;i<a.length();i++){
            dp[i][b.length()]=a.length()-i;
        }
        for ( int i=a.length()-1;i>=0;i--){
            for ( int j=b.length()-1;j>=0;j--){
                int ans=0;
                if( a[i]==b[j]){
                        ans=dp[i+1][j+1];
        }
            else{
                // insert->
                    int insertans=1+dp[i][j+1];
                // remove->
                    int deleteans=1+dp[i+1][j];
                // replace->
                    int replaceans=1+dp[i+1][j+1];
                ans=min(insertans,min(deleteans,replaceans));
        }
          dp[i][j]=ans;

            }
        }
        return dp[0][0];

    }

    int minDistance(string word1, string word2) {
        
        return tabulation(word1,word2);
    }
};

// space optimzation->
class Solution {
public:

    int space(string&a,string&b){

        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);

       for (int j=0;j<b.length();j++){
            next[j]=b.length()-j;
        }
         
        for ( int i=a.length()-1;i>=0;i--){
            for ( int j=b.length()-1;j>=0;j--){
                // [important catch]
                curr[b.length()]=a.length()-i;
                int ans=0;
                if( a[i]==b[j]){
                        ans=next[j+1];
        }
            else{
                // insert->
                    int insertans=1+curr[j+1];
                // remove->
                    int deleteans=1+next[j];
                // replace->
                    int replaceans=1+next[j+1];
                ans=min(insertans,min(deleteans,replaceans));
        }
          curr[j]=ans;

            }
            next=curr;
        }
        return next[0];

    }

    int minDistance(string word1, string word2) {
        if( word1.length()==0){
            return word2.length();
        }
          if( word2.length()==0){
            return word1.length();
        }
        return space(word1,word2);
    }
};



