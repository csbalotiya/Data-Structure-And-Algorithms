#include<bits/stdc++.h>
using namespace std;
void printQueue(queue<int> q){
	while (!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
void fun(queue<int> q){
    if(!q.empty()){
        int temp = q.front();
        q.pop();
        fun(q);
        cout<<temp<<" ";
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    printQueue(q);
    cout<<"\nReverse Queue : ";
    fun(q);
    return 0;
}
