#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int index(int arr[],int num,int n){//sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n ;i++){
            if(arr[i] == num)
                return i;
    }
}
int main(){
    int n = 6;
    int a[n] = {9,1,9,1,6,9};
    int arr[10];
    memset(arr,0,sizeof(arr));
    for(int i = 0;i<n;i++)
        arr[a[i]]+=1;
    for(int i = 0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int j = 0;j<n;j++){
        int temp = *max_element(arr , arr+ 10);
        for(int k = 0;k<temp;k++){
            cout<<index1(arr,temp,10)<<" ";
        }
        arr[index(arr,temp,10)] = -1;
    }

    return 0;
}


'''
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5
'''
