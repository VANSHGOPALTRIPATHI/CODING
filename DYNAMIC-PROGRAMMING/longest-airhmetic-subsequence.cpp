// common diffrence is given in this question->

class solution {
  public:
    int longestsubsequence(vector<int>&arr,int diffrence){
      unordered_map<int,int>dp;
      int ans =0 ;
      for ( int i= 0; i<arr.size();i++){
        int temp=dp[i]-diffrence;
        int tempans=0;
        if (dp.count(temp)){
          tempans=dp[temp];
        }

        dp[arr[i]]=1+tempans;
        ans=max(ans,dp[arr[i]]);
      }

      return ans;
    }
};