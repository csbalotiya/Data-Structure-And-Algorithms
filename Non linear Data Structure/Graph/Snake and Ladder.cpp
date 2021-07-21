#include<bits/stdc++.h>
using namespace std;

map<int, int> lad;
map<int, int> snak;
vector<int> vis;

SnakeAndLadder(int x){

    bool found = false;
    int moves = 0;
    queue<int> q;
    q.push(x);

    while(!q.empty() and !found){
        int cur = q.front();
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die = 0; die <= 6; die++){
                if(t + die == 100){
                   found = true;
                }
                if(t + die <= 100 and lad[t + die] and !vis[lad[t + die]]){

                    vis[lad[t + die]] = true;
                    if(t + die == 100){
                            found = true;
                    }
                    q.push(lad[t+die]);

                }else if(t + die <= 100 and snak[t + die] and !vis[snak[t + die]]){

                    vis[snak[t + die]] = true;
                    if(t + die == 100){
                           found = true;
                    }
                    q.push(snak[t+die]);

                }else if(t + die <= 100 and !lad[t+die] and !snak[t + die] and !vis[snak[t + die]]){

                    vis[t+die] = true;
                    if(t + die == 100){
                            found = true;
                    }
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    found ? cout<<moves : cout<<-1;
}

int32_t main(){

    vis = vector<int>(101, false);
    int ladder,snakes ; cin>>ladder;
    for(int i = 0; i < ladder ; i++){
        int u,v;    cin>>u>>v;
        lad[u] = v;
    }
    cin>>snakes;
    for(int i = 0; i < snakes; i++){
        int u,v;    cin>>u>>v;
        snak[u] = v;
    }
    SnakeAndLadder(1);
}
/*
2
3 90
56 76
3
99 10
30 20
20 5
*/
