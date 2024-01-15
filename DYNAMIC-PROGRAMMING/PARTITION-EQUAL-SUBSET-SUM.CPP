// PROBLEM SATETEMENT->
/*Partition Equal Subset Sum
MediumAccuracy: 30.24%Submissions: 222K+Points: 4
Dive into Premium Learning with Confidence – Win 90% Refund in 90 Days. Discover How 

banner
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.*/



// RECURISON->

  bool solve ( int index , int arr[], int N, int target){
         if ( index>N){
             return 0;
         }
         if ( target==0){
             return 1 ;
         }
         if ( target <0){
             return 0;
         }
         
         bool include = solve ( index +1 , arr ,N , target-arr[index]);
         bool exclude = solve ( index +1 , arr ,N , target);
         
         return (include or exclude);
     }

    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for ( int i=0 ; i<N ;i++){
            total+=arr[i];
        }
        if ( total & 1){
            return 0;
        }
        int target= total/2;
        
        return solve ( 0, arr,N,target);
    }

    // RECURSION + MEMOIZATION ->( TOP- DOWN )->>

    bool solveMEMO ( int index , int arr[], int N, int target,vector<vector<int>>&dp){
         if ( index>=N){
             return 0;
         }
         if ( target==0){
             return 1 ;
         }
         if ( target <0){
             return 0;
         }
        if ( dp[index][target]!=-1){
            return dp[index][target];
        }
         
         bool include = solveMEMO ( index +1 , arr ,N , target-arr[index],dp);
         bool exclude = solveMEMO ( index +1 , arr ,N , target,dp);
         
         return dp[index][target] = include or exclude;
     }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int total=0;
        for ( int i=0 ; i<N ;i++){
            total+=arr[i];
        }
        if ( total & 1){
            return 0;
        }
        int target= total/2;
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        
        return solveMEMO( 0, arr,N,target,dp);
    }

    // tabulation->

     bool solveTAB ( int N,int arr[], int total){
        vector<vector<int>>dp(N,vector<int>(total+1,0));
       for ( int i =0 ; i<= N ;i++){
           dp[i][0]=1;
       }
       
       for ( int index =N-1 ; index>=0 ; index--){
            for ( int target =0 ;target <=total/2;target++){
                bool include=0;
                   if ( target-arr[index]>=0){
                         include = dp[index +1][target-arr[index]];
                   }
                
                 bool exclude = dp[index +1][target-0];
                 
                 dp[index][target] = include or exclude;
            }
       }
       return dp[0][total/2];
        
     }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int total=0;
        for ( int i=0 ; i<N ;i++){
            total+=arr[i];
        }
        if ( total & 1){
            return 0;
        }
        return solveTAB( N, arr,total);
    }

    // space optmization->>
    
    bool spaceoptimization ( int N,int arr[], int total){
       vector<int>curr(total+1, 0);
       vector<int>next(total+1, 0);
       
       curr[0]=1;
       next[0]=1;
       
       for ( int index =N-1 ; index>=0 ; index--){
            for ( int target =0 ;target <=total/2;target++){
                bool include=0;
                   if ( target-arr[index]>=0){
                         include = next[target-arr[index]];
                   }
                
                 bool exclude = next[target-0];
                 
                 curr[target] = include or exclude;
            }
            next=curr;
       }
       return next[total/2];
        
     }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int total=0;
        for ( int i=0 ; i<N ;i++){
            total+=arr[i];
        }
        if ( total & 1){
            return 0;
        }
        return spaceoptimization( N, arr,total);
    }

