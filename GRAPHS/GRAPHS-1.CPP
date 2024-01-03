/*     GRAPHS
graph is a data structure with  nodes and edges 

TYPES OF GRAPH->
1->UNDIRECTED GRAPH  (DOES NOT HAVE -> ONLY (--))
2->DIRECTED GRAPHS    (HAVE -> DIRECTED)

NODE-> ENTITY TO STORE DATA
EDGE-> CONNECTION BETWEEN TWO NODE 

DEGREE IN CASE OF UNDIRECTED-> 
DEGREE -> HOW MANY EDGES ARE LNKED TO A NODE IS KNOWN AS DEGREE OF TAHT NODE 

// DEGREE IN DIRECTED->
DEGREE->
1->IN-DEGREE ->EDGE TOWARDS A NODE 
2->OUT-DEGREE-> EDGE AWAY FROM NODE

WEIGHTED GRAPHS->
1->WEIGTED DIRECTED GRAPH->VALUES GIVEN TO EDGES IN DIRECTED GRAPH MAKE GRAPH A WEIGHTED DIRECTED GRAPH
1->WEIGTED UNDIRECTED GRAPH->VALUES GIVEN TO EDGES IN UNDIRECTED GRAPH MAKE GRAPH A WEIGHTED UNDIRECTED GRAPH

DEAFULT CASE->WHEN NOT SPECIFIED WE CANA ASSUME VALUES TO BE ->  1.

PATH-> DISTANCE BW NODES WHERE A NODE SHOULD NOT REPEAT

------> CYCLIC GRAPH->
WHERE A CYCLE CAN BE FORMED MEANS WE CAN REACH TO THE SAME POSITION BY PATH IS KNOWN AS THE CYCLIC PATH.

ADJACENCY MATRIX-> CONNECTIONS IS TERM OF MATRIC WHERE ISCONNECTED=1,AND NOTCONNECTED=0;
M= NO OF EDGES
N= NO OF NODES

ADJACENCY LIST->
NEIGHBOURS OF A PARTICULAR NODE IS KNOWN AS ADJACENCY LIST..


*/
#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<vector>
// we can make a generic class->
template <typename T>

class graph{
    public:
    unordered_map<T,list<T>>adj;

    void addedge( T u ,T v,bool direction){
        // direction=0->undirected
        // direction=1->directed

        //create a link for u to v
        adj[u].push_back(v);

        if ( direction==0){
            adj[v].push_back(u);
        }

    }
    void printlist(){
        for (auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<" enter the number of nodes ";
    cin>>n;
    int m;
    cout<<" enter the number of edges";
    cin>>m;

    graph<int> g;   // only while creation we have to specify a types i.e for ex->int;

    for (int i=0 ;i<m ;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addedge(u,v,0);

    }
    // printing graph
    g.printlist();
}

//-----------------------------------------------------------------------------------------------------------

//implementation using vector
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int> ans[n];

    for (int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        ans[u].push_back(v);
        //since it is undirected
        ans[v].push_back(u);
    }

    vector<vector<int>>adj(n);
    for (int i=0;i<n;i++){
        adj[i].push_back(i);

        for ( int j=0 ;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}