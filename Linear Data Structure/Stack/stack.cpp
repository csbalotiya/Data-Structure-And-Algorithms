#include<bits/stdc++.h>
using namespace std;
// CPP program to demonstrate working of STL stack
void show(stack <int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
// CPP program to demonstrate working of STL stack
int main(){
    stack<int> s;
    for(int i =10; i< 16 ;i++)
        s.push(i);
    show(s);
    s.pop();
    show(s);
    return 0;
}
