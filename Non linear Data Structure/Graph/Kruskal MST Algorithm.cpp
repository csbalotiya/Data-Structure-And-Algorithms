#include<bits/stdc++.h>
using namespace std;
// Kruskal Algorithm

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

    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
        int u,v,w;    cin>>u>>v>>w;  // u-->v
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    cout<<"\nEdges in MST Are :\n";
    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x  = find_set(u);
        int y  = find_set(v);
        if(x == y){
            continue;
        }else{
            cout<<u<<" "<<v<<"\n";
            union_sets(u,v);
            cost += w;
        }
    }

    cout<<"Cost of minimum Cost Spanning Tree is : "<<cost;
}
/*
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1

Edges in MST Are :
7 8
8 5
4 3
1 2
3 5
2 3
6 7
Cost of minimum Cost Spanning Tree is : 27
*/
