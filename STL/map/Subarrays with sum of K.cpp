//https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1/#


class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k){
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i< N; i++){
            sum += Arr[i];
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum-k];
            
            mp[sum]++;
            
        }
        return ans;
    }
};
