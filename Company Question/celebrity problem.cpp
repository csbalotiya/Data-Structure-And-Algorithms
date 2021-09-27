//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <bits/stdc++.h>
using namespace std;

bool know(vector<vector<int>> &arr, int i, int j){
    return arr[i][j];
}
int main(){

    vector<vector<int>> arr = {{0,0,1,0},
                               {0,0,1,0},
                               {0,0,0,0},
                               {0,0,1,0}};

    int n = arr.size();

    // Approch 1 O[N]
    int count = 0;
    stack<int> st;
    for(int i = 0; i < n; i++){
        st.push(i);
    }
    while(count < n-1){
        int f = st.top();
        st.pop();
        int s = st.top();
        st.pop();
        if(know(arr,f,s))
            st.push(s);
        else
            st.push(f);
        count++;
    }
    cout<<st.top()<<"\n\n\n";


    //Approch 2 By Graph O[n*n]

    int indegree[n] = {0};
    int outdegree[n] = {0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = know(arr,i,j);
            indegree[j] += x;
            outdegree[i] += x;
        }
    }

    for(int i=0; i<n; i++){
        if(indegree[i] == n-1 && outdegree[i] == 0){
            cout<<"Approch second : "<< i;
            break;
        }
    }
}
