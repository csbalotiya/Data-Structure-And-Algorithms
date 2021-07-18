#include<bits/stdc++.h>
using namespace std;
int main(){
    //n = No.of vertex  ,  m = No. of Edges
    int n,m;    cin>>n>>m;
    int count = 0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    //Input of Edges
    for(int i = 0; i < m; i++){
        int u,v;    cin>>u>>v;
        adj[u].push_back(v);        // u --> v
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        count++;
        int x = q.front();
        q.pop();        // x --> v
        cout<<x<<" ";
        for(auto it : adj[x]){
            indeg[it]--;
            if(indeg[it] == 0)
                q.push(it);
        }
    }
}

/*
input :
4 3
0 1
1 2
2 3

Output : 0 1 2 3   // This is Acyclic directed Graph


4 4
0 1
1 2
2 3
3 0

Output : 0   // This is Cyclic Graph

*/
