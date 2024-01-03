// IN DYNAMIC PROGRAMMING->
// GENERALLY WE HAVE TWO APPROACH TO SOLVE A QUESTIONS ->
// 1-> TOP - DOWN APPROACH -> RECURSION + MEMOIZATION( STORES THE VALUE OF SUBPROBLEMS AND STORE IT BY USING MAP/TABLE)
//2-> BOTTOM UP APPROACH ->   TABULATION 
//----------------------------------------------------------------------------------------------------------------------------------

//SOLVING A FIBONACCI QUESTION USING RECURSION AND MEMOIXATION ->



// TOP -DOWN APPROACH =>



#include <bits/stdc++.h>
using namespace std;
#include <vector>

int fibo(int n, vector<int> &dp) {
  if (n <= 1)
    return n;
    // STEP-3

  if (dp[n] != -1)
    return dp[n];

  //STEP->2 
  dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
  return dp[n];
}

int main() {
  
  int n;
  cin >> n;
  //STEP-> 1
  vector<int> dp(n + 1);
  for (int i = 0; i <=n; i++) {
    dp[i] = -1;
  }
  cout << fibo(n, dp) << endl;
}
//*****************************************************************************************************************************************

// BOOTOM -UP APPROCAH =>


#include <bits/stdc++.h>
using namespace std;
#include <vector>

int fibo(int n, vector<int> &dp) {
  if (n <= 1)
    return n;
// initializing by seing base case 
    dp[1]=1;
    dp[0]=0;
// bootom up approcah ->

  for (int i=2 ;i<=n;i++){
    // using array instead of function calling->

    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}

int main() {
  
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  for (int i = 0; i <=n; i++) {
    dp[i] = -1;
  }
  cout << fibo(n, dp) << endl;
}
//*************************************************************************************************************************************

// 3rdd=>  SPACE OPTIMIZATION APPROCH->
#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin>>n;
    // IN THIS WE CAN SEE THAT WE HAVE SOLVE BY JUST USING THENTWO VARIABLES->

      int prev1=1;
      int prev2=0;

      if(n==0){
        return 0;
      }

      for (int i=2;i<=n;i++){
        int curr= prev1 +prev2;
        prev2=prev1;
        prev1=curr;
      }
      cout<<prev1<<endl;
}