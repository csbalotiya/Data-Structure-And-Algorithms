/*   Bubble sort by Recursion   */

/*  We are calling the same function recursively for each element of the array 
    and inside the function, we are looping till the given length of the array, So
  Time complexity is O(n ^ n) = O(n ^ 2).   */


#include<iostream>
using namespace std;

void RecSort(int arr[], int n){

    if(n == 1)
        return ;

    for(int j = 0 ;j < n-1; j++){
        if(arr[j+1] < arr[j]){
            swap(arr[j], arr[j+1]);
        }
    }
   RecSort(arr,n-1);
}
int main(){

    int arr[] = {30,20,10,0,-20};
    int n = sizeof(arr)/sizeof(arr[0]);
    RecSort(arr,n);
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}

