/*Problem statement
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.(x,y,z are choices like(3,5,2))

Detailed explanation ( Input/output format, Notes, Images )*/


/// CODE->>


// recursion->>

#include<limits.h>
int solve(int n, int x, int y, int z){

	if (n==0)
		return 0;

	if (n<0)
		return INT_MIN;
	//x -component
	int a = solve (n-x,x,y,z)+1;
	//y-component
	int b = solve (n-y,x,y,z)+1;
	//z-conponent
	int c = solve (n-z,x,y,z)+1;

	return max(a,max(b,c));
}



int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solve (n,x,y,z);
	if (ans<0){
		return 0;
	}
	else{
			return ans;
	}

}
//******************************************************************************************************************

// recursion + memoization->>

#include<limits.h>
int solve(int n, int x, int y, int z,vector<int>&dp){

	if (n==0)
		return 0;

	if (n<0)
		return INT_MIN;

	if (dp[n]!=-1){
		return dp[n];
	}
	//x -component
	int a = solve (n-x,x,y,z,dp)+1;
	//y-component
	int b = solve (n-y,x,y,z,dp)+1;
	//z-conponent
	int c = solve (n-z,x,y,z,dp)+1;

	dp[n]= max(a,max(b,c));
	return dp[n];
}



int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);
	int ans = solve (n,x,y,z,dp);
	if (ans<0){
		return 0;
	}
	else{
			return ans;
	}

}

//***************************************************************************************************************

// tabulation->>

#include<limits.h>
int solve(int n, int x, int y, int z){
	vector<int> dp (n+1,INT_MIN);

	dp[0]=0;

	for (int i=1 ;i<=n ;i++){
		if (i-x >= 0){
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if (i-y >= 0){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if (i-z >= 0){
			dp[i]=max(dp[i],dp[i-z]+1);
		}	
	}
	if (dp[n]<0)
		return 0;
	else
		return dp[n];	
}



int cutSegments(int n, int x, int y, int z) {
	return solve( n,  x,  y,  z);

}
//**************************************************************************************************************

// space optimixation->>

//  as we can not define them in terms 0f variable or it will tale 
// the same time and space compleity tereefore above is best appeoach
