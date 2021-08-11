// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++
class Solution {
    public:
    int pages(int *arr, int n, int m, int limit){
        int cnt = 1, t1 = 0;
        for(int  i = 0; i < n; i++){
            if(arr[i] > limit){
                cnt = m+1;
            }
            if(t1 + arr[i] > limit){
                cnt += 1;
                t1 = arr[i];
                if(cnt>m)
                    break;
            }else{
                t1 += arr[i];
            }
        }
        return cnt;
    }
    int findPages(int arr[], int n, int m) {
        if(n < m) return -1;
        int sum = 0,mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mx = max(mx,arr[i]);
            sum += arr[i];
        }
        int lo = mx, hi = sum, res;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int cnt = pages(arr,n,m,mid);
            if(cnt > m){
                lo = mid+1;
            }else{
                hi = mid-1;
                res  =mid;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
