/*   Check an array is sorted or not by Recursion   */
#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool Recursion(int *arr, int n){
    if(n == 1){
        return true;
    }
    if(arr[0] < arr[1] && Recursion(arr+1 , n-1)){
            return true;
    }else{
        return false;
    }
}
int main(){
    fast()
    int arr[] = {1,2,3,4,3,5};
    int n = 6;
    Recursion(arr, n-1) ? cout<<"Sorted ":cout<<"Not Sorted ";
    return 0;
}
