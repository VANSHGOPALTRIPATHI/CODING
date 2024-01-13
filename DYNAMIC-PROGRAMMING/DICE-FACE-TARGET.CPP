/*Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

 

Example 1:

Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.*/


// RECURSION->

long long solve ( int dice ,int faces , int target){
      if ( target<0){
          return 0;
      }
      if ( dice==0 && target!=0){
          return 0;
      }
      if ( dice!=0 && target ==0){
          return 0;
      }
      if (target==0 && dice==0 ){
          return 1;
      }
      
      long long ans=0 ;
      
      for ( int i = 1 ; i<= faces ;i++){
          ans = ans+ solve ( dice-1 , faces , target - i);
      }
      return ans ;
  }
  
    long long noOfWays(int M , int N , int X) {
        // code here
        return solve ( N,M,X);
    }

    // RECURISON + MEMOIZATION->

    // TOP DOWN APPROACH ->

     long long solve ( int dice,int faces ,int target,vector<vector<long long>>&dp){
      if ( target<0){
          return 0;
      }
      if ( dice==0 && target!=0){
          return 0;
      }
      if ( dice!=0 && target ==0){
          return 0;
      }
      if (target==0 && dice==0 ){
          return 1;
      }
      if ( dp[dice][target]!=-1){
          return dp[dice][target];
      }
      
      long long ans=0 ;
      
      for ( int i = 1 ; i<= faces ;i++){
          ans = ans+ solve ( dice-1 , faces , target - i,dp);
      }
     dp[dice][target]= ans ;
     return dp[dice][target];
  }
  
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        return solve ( N,M,X,dp);
    }


    // TABULATION->


  long long solvetab (int d,int f ,int t){
      vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
      // after anaylyzing base case ->
      dp[0][0]=1;
      
       for ( int dice=1 ; dice<=d ;dice++){
           for ( int target=1 ; target<=t ;target++){
                 long long ans=0 ;
      
        for ( int i = 1 ; i<= f ;i++){
            if (target-i >= 0){
                ans = ans+ dp[dice-1][target - i];
            }
          
      }
        dp[dice][target]= ans ;
           }
       }
       return dp[d][t];
  }
  
    long long noOfWays(int M , int N , int X) {
        // code here
       
        return solvetab(N,M,X);
    }



    // SPACE OPTIMIZATION ->
      long long SPACE (int d,int f ,int t){
      
      // after anaylyzing base case ->
      
      vector<long long > prev (t+1,0);
      vector<long long > curr (t+1,0);
      prev[0]=1;
      
       for ( int dice=1 ; dice<=d ;dice++){
           for ( int target=1 ; target<=t ;target++){
                 long long ans=0 ;
      
        for ( int i = 1 ; i<= f ;i++){
            if (target-i >= 0){
                ans = ans+ prev[target - i];
            }
          
      }
        curr[target]= ans ;
           }
           prev =curr;
           
       }
       return prev[t];
  }
  
    long long noOfWays(int M , int N , int X) {
        // code here
       
        return SPACE(N,M,X);
    }