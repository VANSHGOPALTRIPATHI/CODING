// WE USE PRIMS ALGORITHM TO FIND MINIMUM SPANNING TREE

// SPANNING TREE->
// Properties of a Spanning Tree:
// A Spanning tree does not exist for a disconnected graph.
// For a connected graph having N vertices then the number of edges in the spanning tree for that graph will be N-1.
// A Spanning tree does not have any cycle.
// We can construct a spanning tree for a complete graph by removing E-N+1 edges, where E is the number of Edges and N is the number of vertices.
// Cayley’s Formula: It states that the number of spanning trees in a complete graph with N vertices isN^{N-2}
// For example: N=4, then maximum number of spanning tree possible =4^{4-2}= 16 .
#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
  // Write your code here.
  // craeting adjance list->
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < g.size(); i++)
  {
    int v = g[i].first.second;
    int w = g[i].second;
    int u = g[i].first.first;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  vector<int> key(n + 1);
  vector<int> mst(n + 1);
  vector<int> parent(n + 1);

  for (int i = 0; i <= n; i++)
  {
    key[i] = INT_MAX;
    parent[i] = -1;
    mst[i] = false;
  }
  // lets start the algorith=>
  parent[1] = -1;
  key[1] = 0;

  for (int i = 1; i < n; i++)
  {
    int mini = INT_MAX;
    int u;

    for (int v = 1; v <= n; v++)
    {
      if (mst[v] == false && key[v] < mini)
      {
        u = v;
        mini = key[v];
      }
      // mark min as true
      mst[u] = true;

      // check its adjacent node->
      for (auto it : adj[u])
      {
        int v = it.first;
        int w = it.second;
        if (mst[v] == false && w < key[v])
        {
          parent[v] = u;
          key[v] = w;
        }
      }
    }
  }
  vector<pair<pair<int, int>, int>> result;
  for (int i = 2; i <= n; i++)
  {
    result.push_back({{parent[i], i}, key[i]});
  }
  return result;
}
