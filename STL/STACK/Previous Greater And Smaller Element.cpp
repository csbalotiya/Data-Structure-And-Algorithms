#include <bits/stdc++.h>
using namespace std;
void previousSmallest(vector<int>& arr){
    int n = arr.size();
    cout<<"\n\nPrevious Smallest Element Array is : ";

    // O[N]
    stack<int> st;
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        if(st.empty()){
            cout<<-1<<" ";
        }else{
            while(!st.empty() && temp < st.top()){
                st.pop();
            }
            if(st.empty())
                cout<<-1<<" ";
            else
                cout<<st.top()<<" ";
        }
        st.push(temp);
    }

    /*Naive Approch O[N*N]
    for(int i = 0; i < n; i++){
        int j = i;
        while(j >= 0){
            if(arr[j] < arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
            if(j == 0)
                cout<<-1<<" ";
            j-=1;
        }
    }*/
}


void previousGreater(vector<int>& arr){
    int n = arr.size();
    cout<<"\n\nPrevious Greater Element Array is : ";

    // O[N]
    stack<int> st;
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        if(st.empty()){
            cout<<-1<<" ";
        }else{
            while(!st.empty() && temp > st.top()){
                st.pop();
            }
            if(st.empty())
                cout<<-1<<" ";
            else
                cout<<st.top()<<" ";
        }
        st.push(temp);
    }

    /*Naive Approch O[N*N]
    for(int i = 0; i < n; i++){
        int j = i;
        while(j >= 0){
            if(arr[j] > arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
            if(j == 0)
                cout<<-1<<" ";
            j-=1;
        }
    }*/
}
int main(){

   vector<int>arr1 = {4,10,5,8,20,15,3,12};
   previousSmallest(arr1);
   //Previous Smallest Element Array is : -1 4 4 5 8 8 -1 3

   vector<int>arr2 = {5,15,20,25,12,20};
   previousSmallest(arr2);
   //Previous Smallest Element Array is : -1 5 15 20 5 12


   cout<<"\n\n";
   previousGreater(arr1);
   //Previous Greater Element Array is : -1 -1 10 10 -1 20 15 15

   previousGreater(arr2);
   //Previous Greater Element Array is : -1 -1 -1 -1 25 25
   return 0;
}
