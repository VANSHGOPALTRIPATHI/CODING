/*A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component. It can only be used in a directed graph.

Difference between Connected and Strongly Connected Components?
Connectivity in a undirected graph refers to whether two vertices are reachable from each other or not. Two vertices are said to be connected if there is path between them. Meanwhile Strongly Connected is applicable only to directed graphs. A subgraph of a directed graph is considered to be an Strongly Connected Components (SCC) if and only if for every pair of vertices A and B, there exists a path from A to B and a path from B to A. Let’s see why the standard dfs method to find connnected components in a graph cannot be used to determine strongly connected components.

*/
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st,
         unordered_map<int, list<int>> &adj) {
  vis[node] = true;
  for (auto nbr : adj[node]) {
    if (!vis[node]) {
      dfs(nbr, vis, st, adj);
    }
  }
  // topo logic
  st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &vis,
            unordered_map<int, list<int>> &adj) {
  vis[node] = true;
  for (auto nbr : adj[node]) {
    if (!vis[nbr]) {
      revdfs(node, vis, adj);
    }
  }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
  // Write your code here.
  // CREATING ADAJANCY LIST=>
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
  }
  stack<int> st;
  unordered_map<int, bool> vis;
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, vis, st, adj);
    }
  }
  // create a transpose garph
  unordered_map<int, list<int>> transpose;
  for (int i = 0; i < v; i++) {
    vis[i] = 0;
    for (auto nbr : adj[i]) {
      transpose[nbr].push_back(i);
    }
  }
  int count = 0;
  while(!st.empty()) {
    int top = st.top();
    st.pop();
    if (!vis[top]) {
      count++;
      revdfs(top, vis, transpose);
    }
  }
  return count;
}