#include<bits/stdc++.h>
using namespace std;
void Clock(vector<vector<int>> & arr){
    int n = arr.size();
    for(int i = 0; i < n/2; i++){
        for(int j = i; j <n-i-1; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[n-j-1][i];
            arr[n-j-1][i] = arr[n-i-1][n-j-1];
            arr[n-i-1][n-j-1] = arr[j][n-i-1];
            arr[j][n-i-1] = temp;

        }
    }
}

int main() {
    vector<vector<int>> arr = { {1,2,3},
                                {4,5,6},
                                {7,8,9}};

    Clock(arr);
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }cout<<"\n";
    }
}
/*
7 4 1
8 5 2
9 6 3*/
