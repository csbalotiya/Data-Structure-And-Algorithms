#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n){
    for(int i = 0;i < n; i++)
        cout<<arr[i]<<" ";
    }
void insertionsort(int arr[],int n){
    for(int i = 0; i < n;i++){
            int key = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j]>key){
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;

    }
    cout<<"\n After sorting :----"<<endl;
    print(arr , n);
}
int main(){
    int arr[] = {111,812,321,4,-50};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    insertionsort(arr,n);

    return 0;
}
