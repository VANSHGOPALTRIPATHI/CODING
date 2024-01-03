
// Dijkstra's Algorithm
// It differs from the minimum spanning tree because the shortest distance between two vertices might not include all the vertices of the graph.

// How Dijkstra's Algorithm works
// Dijkstra's Algorithm works on the basis that any subpath B -> D of the shortest path A -> D between vertices A and D is also the shortest path between vertices B and D.
// Djikstra used this property in the opposite direction i.e we overestimate the distance of each vertex from the starting vertex. Then we visit each node and its neighbors to find the shortest subpath to those neighbors.

// The algorithm uses a greedy approach in the sense that we find the next best solution hoping that the end result is the best solution for the whole problem.

// Example of Dijkstra's algorithm
// It is easier to start with an example and then think about the algorithm.

// Start with a weighted graph









#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>> >adj;
    for (int i=0 ;i<edges;i++){
        int u= vec[i][0];
        int v= vec[i][1];
        int w= vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));


    }

    vector<int>distance(vertices);
    for (int i=0 ;i<vertices;i++){
        distance[i]=INT_MAX;
    }
    set<pair<int,int>>st;
    distance[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record
        auto top=*(st.begin());

        int nodedistance=top.first;
        int topnode=top.second;

        //remove top record
        st.erase(st.begin());

        //traverse neighbour
        for(auto neighbour:adj[topnode]){
            if(nodedistance+neighbour.second<distance[neighbour.first]){
                auto record=st.find(make_pair(distance[neighbour.first],neighbour.first));
                //if record found
                if (record!=st.end()){
                    st.erase(record);
                }
                //distance update
                distance[neighbour.first]=nodedistance+neighbour.second;
                //record pair in set
                st.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }
    return distance;
}
