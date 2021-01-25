#include<bits/stdc++.h>
using namespace std;
/*  SELECTION SORTING PROGRAM   */
void print(int arr[],int n){
    for(int i = 0;i < n; i++)
        cout<<arr[i]<<" ";
    }
void Selectionsort(int arr[],int n){
    for(int i = 0; i < n;i++){
            int minindex = i;
        for(int j = i;j< n;j++){
            if(arr[minindex]>arr[j])
                minindex = j;
        }
    swap(arr[i],arr[minindex]);
    }
    cout<<"\n After sorting :----"<<endl;
    print(arr , n);
}
int main(){
    int arr[] = {111,812,321,4,-50};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    Selectionsort(arr,n);

    return 0;
}
