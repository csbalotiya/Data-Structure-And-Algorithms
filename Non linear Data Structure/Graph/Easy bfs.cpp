#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;


template<typename T>
class Graph{
	map<T,list<T> > adjList;

public:
	Graph(){

	}
	void addEdge(T u, T v,bool bidir=true){

		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void print(){
		//Iterate over the map
		for(auto i:adjList){
			cout<<i.first<<"->";
			//i.second is LL
			for(T entry:i.second){
				cout<<entry<<",";
			}
			cout<<endl;
		}
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
			for(int neigbour :adjList[node]){
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
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 6);

	g.bfs(1);
}

