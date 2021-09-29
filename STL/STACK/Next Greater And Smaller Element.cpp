#include <bits/stdc++.h>
using namespace std;
void nextGreater(vector<int>& arr){
    int n = arr.size();
    cout<<"\n\nNext Greater Element Array is : ";

    // O[N]
    int ans[n];
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        int temp = arr[i];
        if(st.empty()){
            ans[i] = -1;
        }else{
            while(!st.empty() && temp > st.top()){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(temp);
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i]<<" ";
}


void nextSmaller(vector<int>& arr){
    int n = arr.size();
    cout<<"\n\nNext Greater Element Array is : ";

    // O[N]
    vector<int> ans;
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        int temp = arr[i];
        if(st.empty()){
            ans.push_back(-1);
        }else{
            while(!st.empty() && temp < st.top()){
                st.pop();
            }
            int t = st.empty() ? -1 : st.top();
            ans.push_back(t);
        }
        st.push(temp);
    }
    for(int i = n-1; i >= 0; i--)
        cout<<ans[i]<<" ";
}


int main(){

   vector<int>arr1 = {4,10,5,8,20,15,3,12};
   nextGreater(arr1);
   //Next Greater Element Array is : 10 20 8 20 -1 -1 12 -1

   vector<int>arr2 = {5,15,20,25,12,20};
   nextGreater(arr2);
   //Previous Greater Element Array is : 15 20 25 -1 20 -1


   cout<<"\n\n";
   nextSmaller(arr1);
   //Next Smallest Element Array is : 3 5 3 3 15 3 -1 -1
   nextSmaller(arr2);
   //Next Smallest Element Array is : -1 12 12 12 -1 -1
   return 0;
}
