//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
    
        sort(arr,arr+n);
        int ans = arr[n-1] - arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] < k)
                continue;
            else{
                int mx = max(arr[i-1]+k,arr[n-1]-k);
                int mn = min(arr[0]+k, arr[i]-k);
                ans = min(ans, mx-mn);
            }
        }
        return ans;
    }
};
