#include<bits/stdc++.h>
using namespace std;
int find_max(int a[],int i,int l){
    int maxm;
    if (i >= l-2){
        if (a[i] > a[i+1])
            return a[i];
        else
            return a[i+1];
    }
    maxm = find_max(a,i+1,l);

    if (a[i] > maxm)
        return a[i];
    else
        return maxm;

    return maxm;
}

int find_min(int a[],int i,int l){
    int minm;
    if (i >= l-2){
        if (a[i] < a[i+1])
            return a[i];
        else
            return a[i+1];
    }
    minm = find_min(a,i+1,l);

    if (a[i] < minm)
        return a[i];
    else
        return minm;

    return minm;
}

int main() {
    int a[] = {2,3,56,7,8,1,9,7889,3,4};
    size_t l = sizeof(a)/sizeof(a[0]);

    cout<<"Maximum Number in arr is : "<<find_min(a,0,l)<<endl;
    cout<<"Maximum Number in arr is : "<<find_max(a,0,l)<<endl;
	return 0;
}
