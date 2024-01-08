/*Largest square formed in a matrix
MediumAccuracy: 36.98%Submissions: 78K+Points: 4
90% Refund available on all premium courses 
Discover How  

banner
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.*/

// recursive soln->

 int solve (vector<vector<int>> &mat,int row,int col,int &maxi){
        if( row>=mat.size() || col>=mat[0].size()){
            return 0;
        }
        int right= solve(mat,row,col+1,maxi);
        int diagonal=solve(mat,row+1,col+1,maxi);
        int down=solve(mat,row+1,col,maxi);
        
        if(mat[row][col]==1){
            int ans = 1+  min(right,min(diagonal,down));
            int maxi=max(maxi,ans);
            return ans;
            
            
        }
        else{
            return 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        solve ( mat,0,0,maxi);
        return maxi;
    }

    // recurision + meoization->

    
    int solvememo(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>>&dp){
        if( i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right= solvememo(mat,i,j+1,maxi,dp);
        int diagonal=solvememo(mat,i+1,j+1,maxi,dp);
        int down=solvememo(mat,i+1,j,maxi,dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 +  min(right,min(diagonal,down));
            int maxi= max(maxi , dp[i][j]);
            return  dp[i][j];
        }
        else{
            return  dp[i][j]=0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solvememo( mat,0,0,maxi,dp);
        return maxi;
    }

    //tabulation->>
    int solvetabular(vector<vector<int>> &mat,int &maxi){
     int row= mat.size();
     int col= mat[0].size();
     vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
     for ( int i=row-1;i>=0;i--){
         for (int j=col-1;j>=0;j--){
             
             int right=dp[i][j+1];
             int diagonal=dp[i+1][j+1];
             int down=dp[i+1][j];
             
             if (mat[i][j]==1){
                  dp[i][j] = 1+ min(right,min(diagonal,down));
                 int maxi=max(maxi,dp[i][j]);
                 }
                 else{
                     dp[i][j]=0;
                 }
         }
     }
     return dp[0][0];
 }
 // space optimization->>

 int solveSO(vector<vector<int>> &mat,int &maxi){
     int row= mat.size();
     int col= mat[0].size();
     
     vector<int>curr(col+1,0);
     vector<int>next(col+1,0);
     for ( int i=row-1;i>=0;i--){
         for (int j=col-1;j>=0;j--){
             
             int right=curr[j+1];
             int diagonal=next[j+1];
             int down=next[j];
             
             if (mat[i][j]==1){
                  curr[j] = 1+ min(right,min(diagonal,down));
                 int maxi=max(maxi,curr[j]);
                 }
                 else{
                     curr[j]=0;
                 }
         }
         next=curr;
         
     }
     return next[0];
 }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        solveSO(mat,maxi);
        return maxi;
    }