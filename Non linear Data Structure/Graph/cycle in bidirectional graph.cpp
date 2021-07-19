#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool>&visited, int parent){

    visited[src] = true;
    for(auto i : adj[src]){
        if(i != parent){
            if(visited[i])
                return true;
            if(!visited[i] and isCycle(i,adj,visited,src)){
                return true;
            }
        }
     }
    return false;
}

int32_t main(){

    int n,m;    cin>>n>>m; // n-> Vertex, m-> Edges
    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);
    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;  // u-->v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i = 0; i < n; i++){
        if(!visited[i] and isCycle(i,adj,visited,-1)){
            cycle = true;
        }
    }


	if(cycle)
		cout<<"Cyclic Graph";
	else
		cout<<"Non cyclic!";
}


/*
Input :
4 3
0 1
1 2
2 0
Cyclic Graph

Input :
4 3
0 1
1 2
2 3
Non cyclic!
*/
