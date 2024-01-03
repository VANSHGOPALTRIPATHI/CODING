/*    BFS  -> [BREADTH FIRST SEARCH]
BFS IS GENERALLY A TRAVERSAL TECHNIQUES IN GRAPHS 

TRAVERSE ALL THE NODES AND RETURN ALL THE NODE ONCE WITHOUT REPEATING

In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. The BFS traversal should include all nodes directly or indirectly connected to vertex 0.

Note:
The traversal should proceed from left to right according to the input adjacency list.


*/
#include<iostream>
using namespace std;
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<set>

//-------------------------------------------------------------------------------------

void prepareadjlist( unorderd_map<int,list<int>> &adjlist,vector<pair<int,int>> &edges){
    for (int i=0 ;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void bfs(unorderd_map<int,list<int>>&adjlist,unorderd_map<int,bool>&visited,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;

    while (!q.empty()){
        int frontnode=q.front();
        q.pop();
        // store front node into ans  ->
        ans.push_back(frontnode);
        //traversing all neighbours of fron node 
        for(auto i: adjlist[frontnode]){
            if (!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }

    }
}

vector<int> bfsTraversal(int vertex, vector<pair<int,int>> &edges){
    // Write your code here.
    unorderd_map<int,list<int>>adjlist;
    vector<int>ans;
    unorderd_map<int,bool>visited;
    prepareadjlist(adjlist,edges);

    //traverse all component of a graph->
    for(int i=0 ;i<vertex.size();i++){
        if (!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }
}