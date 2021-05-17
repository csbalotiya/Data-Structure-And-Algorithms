
/* Complexity O[Log(n)]

 best-case time complexity would be O(1) when the central index would directly match the desired value. 
 The worst-case scenario could be the values at either extremity of the list or values not in the Array.*/


#include<iostream>
using namespace std;


int bsearch(int a [],int l,int h,int x){
        int mid = (l + h)/2;
        if (x == a[mid])
            return mid;
        else if(x > a[mid]){
            return bsearch(a,mid+1,h,x);
        }else if(x < a[mid]){
            return bsearch(a,l,mid-1,x);
        }
        else
            return -1;
}
int main(){
        int a [] = {3,15,17,29,56,98,100};
        int fnd = 56;
        size_t s = sizeof(a)/sizeof(a[0]);
        int low = 0, high = s-1 ;
        cout<<bsearch(a,low,high,fnd);
        return 0;
}


// Thank you
