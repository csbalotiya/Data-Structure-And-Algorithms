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

    void dfsHelper(T node,map<T,bool> &visited){
            //Whenever to come to a node, mark it visited
            visited[node] = true;
            cout<<node<<" ";

            //Try to find out a node which is neigbour of current node and not yet visited
            for(T neighbour: adjList[node]){
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited);
                }
            }
        }

	void dfs(T src){
		map<T,bool> visited;
		dfsHelper(src,visited);
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

	cout<<"DFS Traversal is : \n";
	g.dfs(1);

}
