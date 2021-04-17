//searching an element in O[1]by Hashing
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
bool hashTable[MAX+1][2];

void Insert(int arr[] ,int n){
    for(int i= 0 ; i <n;i++){
        if(arr[i] >= 0)
            hashTable[arr[i]][0] = 1;
        else
            hashTable[abs(arr[i])][1] = 1;
    }
}

int Search(int x){
    if(hashTable[x] >= 0)
           return hashTable[x][0];
    else
        return hashTable[abs(x)][1];
}

int main() {
    int n = 6;
    int arr[] = {200,35,-3,67,0,56};
    Insert(arr,n);
    int findValue = 167;

    cout<<Search(findValue);
	return 0;
}
