/**/

// RECURISON->

class solution{
  public:
  bool solve ( string&str,string&pattern,int i,int j){
    if (i<0 && j< 0){
      return false;
    }
    if( i>=0 && j<0 ){
      return false;
    }
    if (i<0 && j>=0){
      for(int k=0 ;k<=j ;k++){
        if(pattern[k]!='*'){
          return false;
        }
      }
    }
    return true;

    // match
    if (str[i]==pattern[j] || pattern[j]=='?'){
      return solve(str,pattern,i-1,j-1);
    }
    else if(pattern[j]=='*'){
      return (solve(str,pattern,i-1,j)||solve(str,pattern,i,j-1));
    }
    else{
      return false;
    }
  }

  bool ismatch(string s ,string p){
    return solve(s,p,s.length()-1,p.lenght()-1);
  }
}
// recurision + dp ->

class solution{
  public:
  bool solve ( string&str,string&pattern,int i,int j,vector<vector<int>>&dp){
    if (i<0 && j< 0){
      return false;
    }
    if( i>=0 && j<0 ){
      return false;
    }
    if (i<0 && j>=0){
      for(int k=0 ;k<=j ;k++){
        if(pattern[k]!='*'){
          return false;
        }
      }
    }
    else{
      return true;
    }
    if(dp[i][j]!=-1){
      return dp[i][j];
    }
    

    // match
    if (str[i]==pattern[j] || pattern[j]=='?'){
      return dp[i][j]=  solve(str,pattern,i-1,j-1,dp);
    }
    else if(pattern[j]=='*'){
      return dp[i][j]= (solve(str,pattern,i-1,j,dp)||solve(str,pattern,i,j-1,dp));
    }
    else{
      return false;
    }
  }

  bool ismatch(string s ,string p){
    vector<vector<int>>dp(s.length(),vector<int>p.legth(),-1);
    return solve(s,p,s.length()-1,p.lenght()-1,dp);
  }
}

// tabulation-.>
