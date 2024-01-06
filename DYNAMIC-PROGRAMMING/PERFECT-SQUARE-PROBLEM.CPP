/*Get Minimum Squares
Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).
 

Example 1:

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100*/

// recursion->
	int solve(int n)
	{
	    // Code here
	    if(n==0){
	        return 0;
	    }
	    int ans =n;
	    for (int i=1;i*i<=n;i++){
	        ans=min(ans,1+solve(n-i*i));
	    }
	    return ans;
	    
	}
	int MinSquares(int n){
	    return solve(n);
	}

  //************************************************************************************************
// recursion + memoization->


  		int solve(int n,vector<int>&dp)
	{
	    // Code here
	    if(n==0){
	        return 0;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int ans =n;
	    for (int i=1;i*i<=n;i++){
	        ans=min(ans,1+solve(n-i*i,dp));
	        
	    }
	    dp[n]=ans;
	    return dp[n];
	    
	}
	int MinSquares(int n){
	    vector<int>dp(n+1,-1);
	    return solve(n,dp);
	}

  //******************************************************************************************************


  //tabualtion->

  	int solvetab(int n)
	{
	    // Code here
	    vector<int>dp(n+1,INT_MAX);
	    dp[0]=0;
	    int ans =n;
	    for (int i=1;i<=n;i++){
	        for (int j=1;j*j<=n;j++){
	            int temp=j*j;
	            if(i-temp>=0){
	                dp[i]=min(dp[i],1+dp[i-temp]);
	            }
	        
	    }
	    }
	    return dp[n];
	    
	}
	int MinSquares(int n){
	    return solvetab(n);
	}
//***********************************************************************************************************


//space optimization-->>>>

 // SAME SPACE WILL BE TAKEN SO MORE OPTIMIZE CAN NOT BE DONE AS IT DEPEND UPON dp[i],1+dp[i-num[j]] CAN NOT BE DECLARED AS VARIABLE



