#include<bits/stdc++.h>
using namespace std;
// Cycle detection Using Disjoint Set / Union Find

const int N = 1e5+6;
int n,m;   // n-> Vertex, m-> Edges
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int32_t main(){

    for(int i = 0; i < N; i++)
        make_set(i);

    bool cycle = false;
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;  // u-->v
        edges.push_back({u,v});
    }

    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int x  = find_set(u);
        int y  = find_set(v);
        if(x == y){
            cycle = true;
        }else{
            union_sets(u,v);
        }
    }

    cycle ? cout<<"Cycle is Present" : cout<<"No cycle";
}
/*
4 4
0 1
1 2
2 3
3 0
Cycle is Present

Input
3 2
0 1
1 2
No cycle
*/
