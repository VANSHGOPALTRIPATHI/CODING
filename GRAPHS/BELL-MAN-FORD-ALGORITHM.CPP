/*Problem statement
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.



Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.



Note:
If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.*/
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    // n-1 times

    for ( int i=1;i<=n;i++){
        //traverse on edge list->
        for (int j=0 ;j<m;j++){
            int u= edges[j][0];
            int v= edges[j][1];
            int wt= edges[j][2];

            if (dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // check for negative edge->
    bool flag=0;
     for (int j=0 ;j<m;j++){
            int u= edges[j][0];
            int v= edges[j][1];
            int wt= edges[j][2];

            if (dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                flag=1;
            }
        }
        if (flag==0){
            return dist[dest];
        }

        return -1;
        
        

 }