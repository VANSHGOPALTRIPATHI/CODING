


/*  BRIDGE=>>>  

An edge in an undirected connected graph is a bridge if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar, a bridge is an edge removal that increases the number of disconnected components. 

Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks.*/







#include <list>
#include <unordered_map>
#include <vector>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {
  vis[node] = true;
  low[node] = disc[node] = timer++;

  for (auto nbr : adj[node]) {
    if (parent == nbr) {
      continue;
    }
    if (!vis[nbr]) {
      dfs(nbr, node, timer, disc, low, result, adj, vis);
      low[node] = min(low[node], low[nbr]);
      // check bridge node
      if (low[nbr] > disc[node]) {
        vector<int> ans;
        ans.push_back(node);
        ans.push_back(nbr);
        result.push_back(ans);
      }
    } else {
      // back edge
      low[node] = min(low[node], disc[nbr]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
  // Write your code here
  // CREATING ADAJANCY LIST=>
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < e; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int timer = 0;
  vector<int> disc(v);
  vector<int> low(v);
  int parent = -1;
  unordered_map<int, bool> vis;

  for (int i = 0; i < v; i++) {
    low[i] = -1;
    disc[i] = -1;
  }

  // dfs
  vector<vector<int>> result;
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, parent, timer, disc, low, result, adj, vis);
    }
  }
  return result;
}