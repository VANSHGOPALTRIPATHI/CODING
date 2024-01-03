

/*ARTICULATION POINT=>
Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more components. They are useful for designing reliable networks.*/








#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

int min(int a ,int b){
  if (a<b){
    return a;
  }
  else{
    return b;
  }
}

void dfs(int node, int parent, vector<int> &disc, vector<int> &low,unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj,vector<int> &ap,int &timer) {
  vis[node] = true;
  low[node] = disc[node] = timer++;
  int child =0;

  for (auto nbr : adj[node]) {
    if (parent == nbr) {
      continue;
    }
    if (!vis[nbr]) {
      dfs(nbr, node, disc, low, vis, adj, ap,timer);
      low[node] = min(low[node], low[nbr]);
      // check ap or not
      if (low[nbr] >= disc[node]&& parent!=-1) {
        ap[node]=1;}
        child++;
      }
    else {
      // back edge
      low[node] = min(low[node], disc[nbr]);
    }
  }
  if(parent==-1 && child>1){
    ap[node]=1;
  }
}

int main(){
  // CREATING ADAJANCY LIST=>
  int n=5;
  int e=5;

  vector<pair<int,int>>edges;
  edges.push_back(make_pair(0,3));
  edges.push_back(make_pair(3,4));
  edges.push_back(make_pair(0,4));
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < e; i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int timer = 0;
  vector<int> disc(n);
  vector<int> low(n);
  vector<int>ap(n,0);
  int parent = -1;
  unordered_map<int, bool> vis;

  for (int i = 0; i < n; i++) {
    low[i] = -1;
    disc[i] = -1;
  }

  // dfs
  vector<vector<int>> result;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, -1,disc,low,vis,adj,ap,timer);
    }
}
// PRINT ARTICULATION POINT->

cout<<" articulation points are as folllows ->"<<endl;
for (int i=0;i<n;i++){
  if(ap[i]!=0){
    cout<<i<<" ";
  }
}cout<<endl;

}

// correct code;