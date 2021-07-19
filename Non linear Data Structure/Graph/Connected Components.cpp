//Connected Component graph
#include<bits/stdc++.h>
using namespace std;

//Q. Find the no. of connected components in a graph and its size ?
int visit_comp(int src, vector<bool> &visited, vector<vector<int>>&adj){
        if(visited[src])
            return 0;
        int ans = 1;
        visited[src] = true;
        for(auto it : adj[src]){
            if(!visited[it]){
                   ans += visit_comp(it,visited,adj);
                   visited[it] = true;
            }
        }
        return ans;
}

int main(){
    int n,m;   // n-> Vertex, m-> Edges
    cin>>n>>m;
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;  // u-->v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n,false);
    vector<int> components;
    for(int i = 0; i < n; i++){
        if(!visited[i] ){
            components.push_back(visit_comp(i,visited,adj));
        }
    }

    cout<<"Number of Component in graph is "<<components.size()
        <<"\nAnd Size of components are ";
    for(int x : components){
        cout<<x<<" ";
    }
}
/*
Input 
5 3
0 1
2 3
0 4
Number of Component in graph is 2
And Size of components are 3 2
*/


