#include <bits/stdc++.h>
bool checkcycledfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
        {
            bool cycledetected = checkcycledfs(neighbour, visited, dfsvisited, adjlist);
            if (cycledetected)
            {
                return true;
            }
            else if (dfsvisited[neighbour])
            {
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
}

    int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
    {
        // Write your code here.
        // CREATE ADAJENCY LIST->
        unordered_map<int, list<int>> adjlist;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            adjlist[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                bool ans = checkcycledfs(i, visited, dfsvisited, adjlist);
            }
            if (ans)
            {
                return true;
            }
        }
        return false;
    }