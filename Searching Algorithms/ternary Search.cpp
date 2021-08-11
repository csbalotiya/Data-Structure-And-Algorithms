//https://practice.geeksforgeeks.org/problems/3d27d4683c121c1f152ee8f41279255dc4430cf6/1/

//Complexity O[LOG base3 N]
#include<bits/stdc++.h>
using namespace std;
int ternarySearch(int *a, int n, int x){
    int l = 0,h = n-1,mid1,mid2,ind = -1;
    while(l <= h){
        mid1 = l + (h-l)/3;
        mid2 = h - (h-l)/3;
        if(a[mid1] == x){
            ind = mid1;
            break;
        }
        if(a[mid2] == x){
            ind = mid2;
            break;
        }
        if(x < a[mid1]){
            h = mid1-1;
        }else if(x > a[mid2]){
            l = mid2+1;
        }else{
            l = mid1+1;
            h = mid2-1;
        }
    }
    return ind;
}
int main(){

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int x = 3;
    int n = 10;
    int ind = ternarySearch(a,n,x);
    (ind == -1) ? cout<<"Not Found " : cout<<"Value at index : "<<ind;

}
