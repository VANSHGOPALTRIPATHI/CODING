#include<iostream>
using namespace std;
#include<vector>
/*                PROBLEM STATEMENT->
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it. Return the list of paths in lexicographically increasing order.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.*/
#include <bits/stdc++.h> 
 bool issafe(int newx,int newy,vector<vector<bool>>&vis,vector < vector < int >> &arr,int n){
     if ((newx>=0 && newx<=n)&&(newy>=0&&newy<n)&& (vis[newx][newy]!=1)&&(arr[newx][newy]==1)){
         return true;
     }
     else{
         return false;
     }
 }
 
 void solve(int x, int y,vector < vector < int >> &arr,int n,vector<string>&ans,vector<vector<bool>>&vis, string path ){
    //base case 
    if ( x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }    
    // D,l,R,U
  
    vis[x][y]=1;
      //Down
    if(issafe(x+1,y,vis ,arr,n)){
        solve(x+1, y, arr,n, ans, vis,  path+'D');
        
    }
    //left
    if(issafe(x,y-1,vis ,arr,n)){
        solve(x, y-1, arr,n, ans, vis,  path+'L');
        
    }
    //right
    if (issafe(x, y + 1, vis, arr, n)) {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    //Upp
    if(issafe(x-1,y,vis ,arr,n)){
        solve(x-1, y, arr,n, ans, vis,  path+'U');
        
    }
    vis[x][y]=0;
 }


vector < string > searchMaze(vector < vector < int >> &arr, int n) {
    // Write your code here.
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path="";
    if (arr[0][0] == 0) {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
 