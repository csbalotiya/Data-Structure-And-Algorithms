#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T , list<int>> adjList;

public:
    Graph(){}
    void print(){
        for(auto v : adjList){
            cout<<v.first<<" -> ";
            for(T t : v.second)
                cout<<t<<" ";
            cout<<endl;
        }
    }
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void dfsHelper(T s, map<T, bool> &visited){
        visited[s] = true;
        cout<<s<<" ";
        for(T nib : adjList[s]){
            if(!visited[nib]){
                dfsHelper(nib, visited);
            }
        }cout<<"\n\n";
    }
    void dfs(T src){
        map<T, bool> visited;
        dfsHelper(src, visited);
    }

    void bfs(T src){
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;

        for(auto node : adjList){
                dist[node.first]= INT_MAX;
        }

        q.push(src);
        parent[src] = src;
        dist[src] = 0;


        while(!q.empty()){

            T node = q.front();
            cout<<node<<" ";
            q.pop();

            for(T nei : adjList[node]){
                if(dist[nei] == INT_MAX){
                    q.push(nei);
                    dist[nei] = dist[node] + 1;
                    parent[nei] = node;
                }
            }
        }cout<<"\n\n";
        for(auto i:adjList){
				T node = i.first;
				cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
		}
    }

};

int main(){
	Graph<int> g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 6);

	//g.print();
	//cout<<"DFS Traversal is : \n";
	//g.dfs(1);

	cout<<"BFS Traversal is : \n";
	g.bfs(1);

}
