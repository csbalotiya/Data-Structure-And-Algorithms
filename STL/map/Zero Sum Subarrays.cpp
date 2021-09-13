//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll, ll> mp;
        ll sum = 0, ans = 0, k = 0;
        mp[0] = 1;
        for(int i = 0; i< n; i++){
            sum += arr[i];
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum-k];
            
            mp[sum]++;
            
        }
        return ans;
    }
};
