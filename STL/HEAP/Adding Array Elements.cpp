//https://practice.geeksforgeeks.org/problems/adding-array-element4756/1#


#include <bits/stdc++.h>

using namespace std;

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        
       priority_queue<int, vector<int>, greater<int> >pq;
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        int c = 0;
        while(pq.top()< k){
            c++;
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            pq.push(temp1+temp2);
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
