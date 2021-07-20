#include<bits/stdc++.h>
using namespace std;
// Prims Algorithm
//Time Complexity of the program is O(V^2)
const int N = 1e5+3;
int n,m;   // n-> Vertex, m-> Edges
vector<vector<int>> g[N];
vector<int> dist(N), parent(N);
vector<bool> vis(N);
const int INF = 1e9;
int cost = 0;

void primsMST(int src){
    for(int i = 0; i < n; i++)
        dist[i] = INF;

    set<vector<int>> s;        //  It Already provide data in sorted order
    dist[src] = 0;
    s.insert({0,src});             //set({ weight, node})
    while(!s.empty()){

        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;           //x[1] - node
        int u = x[1];               // u = node
        int v = parent[x[1]];       // u--> v  v(parent of u)
        int w = x[0];               // weight in x[0] in set
        cout<<u<<" "<<v<<" "<<w<<"\n";
        cost += w;

        for(auto it : g[u]){        // Neighbour of node u
            int node = it[0];
            int weight = it[1];
            if(vis[node])           // Eg: node1 --> {node2, weight}
                continue;
            if(dist[node] > weight){
                s.erase({dist[node], node});
                dist[node] = weight;
                s.insert({dist[node], node});
                parent[node] = x[1];
            }
        }
    }
}

int32_t main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v,w;    cin>>u>>v>>w;  // u-->v
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout<<"\nEdges In MST : \n";
    primsMST(0);
    cout<<"Cost of minimum Cost Spanning Tree is : "<<cost;
}

/*
Input :
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40

Output :
Edges In MST :
0 0 0
2 0 5
1 0 10
3 1 2
Cost of minimum Cost Spanning Tree is : 17*/
