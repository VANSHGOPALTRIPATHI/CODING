/*Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.*/

// recurison->


int solve(int n, vector<int>&days, vector<int> &cost,int index){
    if ( index>=n){
        return 0;
    }

    // 1 day pass->
    int option1=cost[0]+solve(n,days,cost,index+1);

    int i;
    // 7 day pass->
    for (i=index;i<n && days[i]<days[index]+7;i++);

    int option2= cost[1]+solve(n,days,cost,i);

    // 30 days passs->
    for (i=index;i<n && days[i]<days[index]+30;i++);

    int option3= cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve( n,days,cost,0);
}

// recusion+ memoization->


int solve(int n, vector<int>&days, vector<int>&cost,int index, vector<int>&dp){
    if ( index>=n){
        return 0;
    }

    if (dp[n]!=-1){
        return dp[n];
    }

    // 1 day pass->
    int option1=cost[0]+solve(n,days,cost,index+1,dp);

    int i;
    // 7 day pass->
    for (i=index;i<n && days[i]<days[index]+7;i++);

    int option2= cost[1]+solve(n,days,cost,i,dp);

    // 30 days passs->
    for (i=index;i<n && days[i]<days[index]+30;i++);

    int option3= cost[2]+solve(n,days,cost,i,dp);

    dp[index]= min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solve( n,days,cost,0,dp);
}

// tabulation->


// 1 day pass->
    int option1=cost[0]+solve(n,days,cost,index+1);

    int i;
    // 7 day pass->
    for (i=index;i<n && days[i]<days[index]+7;i++);

    int option2= cost[1]+solve(n,days,cost,i);

    // 30 days passs->
    for (i=index;i<n && days[i]<days[index]+30;i++);

    int option3= cost[2]+solve(n,days,cost,i);

    dp[index]= min(option1,min(option2,option3));
    return dp[index];

    // spaceoptimization->


    
    int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans =0;
    queue<pair<int,int>>month;
    queue<pair<int,int>>week;

    for (int day:days){

      // step-1-remove expire days->
      while(!month.empty()  &&  month.front().first+30<=day)
          month.pop();

      while(!week.empty()  && week.front().first +7 <=day)
          week.pop();

          //step-> 2 add cost for curr day->
          week.push(make_pair(day,ans+cost[1]));
          month.push(make_pair(day,ans+cost[2]));

          // step-3 ans upadte->
          ans=min(ans+cost[0],min(week.front().second,month.front().second));

    }
    return ans;
}