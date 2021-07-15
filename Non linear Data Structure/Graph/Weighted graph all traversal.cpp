#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    //map<T , list<int>> adjList;
    map<T , list<pair<T, int>>>  adjList;

public:
    Graph(){}
    void print(){
        for(auto v : adjList){
            cout<<"Node "<<v.first<<" make Edge with :\n";
            for(auto t : v.second)
                cout<<t.first<<" and weight is "<<t.second<<endl;
            cout<<endl;
        }
    }


    void addEdge(T u, T v, int w, bool bidir = true){

        adjList[u].push_back({v,w});
        if(bidir){
            adjList[v].push_back({u,w});
        }
    }

    void dfsHelper(T s, map<T, bool> &visited){
        visited[s] = true;
        cout<<s<<" ";
        for(auto t : adjList[s]){
            T nib = t.first;
            if(!visited[nib]){
                dfsHelper(nib, visited);
            }
        }
    }
    void dfs(T src){
        map<T, bool> visited;
        dfsHelper(src, visited);
    }


    void bfs(T src){
		queue<T> q;
		map<T,bool> visited;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			T node = q.front();
			cout<<node<<" ";
			q.pop();

			// For the neigbours of the current node, find out the nodes which are not visited
			for(auto x :adjList[node]){
                T neigbour = x.first;
				if(!visited[neigbour]){
					q.push(neigbour);
					visited[neigbour] = true;
				}
			}
		}
	}


};

int main(){
	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 4, 8);
	g.addEdge(2, 5, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(4, 5, 3);
	g.addEdge(4, 6, 2);
	g.addEdge(5, 6, 5);

	cout<<"Graph Info : \n";
	g.print();

	cout<<"\n\nDFS Traversal is : \n";
	g.dfs(1);

	cout<<"\n\nBFS Traversal is : \n";
	g.bfs(1);

}
