// A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

// Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

// For example, Consider the DAG shown in the picture.
#include <bits/stdc++.h> 



void toposort(int node,vector<bool>&visited(v),stack<int>&s,unordered_map<int, list<int>> adjlist){
    visited[node]=true;
    
    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            toposort(neighbour,visited,s,adjlist);
        }
    }
    //important
    s.push(node);
}



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
     unordered_map<int, list<int>> adjlist;
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
        }

        vector<bool>visited(v);
        stack<int>s;
        for (int i=0 ;i<v;i++){
            if(!visited[i]){
                toposort(i,visited,s,adjlist);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
}
