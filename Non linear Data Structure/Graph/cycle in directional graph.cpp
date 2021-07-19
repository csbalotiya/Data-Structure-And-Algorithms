#include<bits/stdc++.h>
using namespace std;


//Cycle in Directed graph
bool isCycle(int src, vector<vector<int>> &adj, vector<bool>&visited, vector<int>& stack){

    visited[src] = true;
    stack[src] = true;
    for(auto i : adj[src]){
            if(!visited[i] and isCycle(i,adj,visited,stack))
                return true;

            if(stack[i])
                return true;
    }
    stack[src] = false;
    return false;
}

int main(){

    int n,m;    cin>>n>>m; // n-> Vertex, m-> Edges
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;  // u-->v
        adj[u].push_back(v);
    }

    bool cycle = false;
    vector<bool> visited(n,false);
    vector<int> stack(n,0);
    for(int i = 0; i < n; i++){
        if(!visited[i] and isCycle(i,adj,visited,stack)){
            cycle = true;
        }
    }

	if(cycle)
		cout<<"Cyclic Graph";
	else
		cout<<"Non cyclic!";
}

/*
INPUT:
4 4
0 1
1 2
2 3
3 0
Cyclic Graph


INPUT: 
4 4
0 1
2 1
2 3
3 0
Non cyclic
*/
