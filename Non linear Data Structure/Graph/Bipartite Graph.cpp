//Bipartite graph : graph is 2 colorable
#include<bits/stdc++.h>
using namespace std;

int n,m;   // n-> Vertex, m-> Edges
vector<bool> visited;
vector<int> col;
vector<vector<int>> adj;
bool bipart ;

void color(int src, int curr){
        if(col[src] != -1 and col[src] != curr){
            bipart = false;
            return;
        }
        col[src] = curr;
        if(visited[src])
            return;     // No need to check its neighbours

        visited[src]= true;
        for(int it : adj[src]){
            color(it, curr xor 1);
            // 1 xor 0 = 1
            // 1 xor 1 = 0
        }
}

int main(){
    bipart = true;
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    col = vector<int>(n,-1);

    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;  // u-->v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i] ){
            color(i,0);
        }
    }

    bipart ? cout<<"Graph is Bipartite" : cout<<"Graph is Not bipartite";
}
/*
Input
3 3
0 1
1 2
2 0
Graph is Not bipartite

Input:
4 4
0 1
1 2
2 3
3 0
Graph is Bipartite
*/
