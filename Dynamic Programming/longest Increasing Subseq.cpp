//https://leetcode.com/problems/longest-increasing-subsequence/submissions/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp = {nums[0]};
        for(int i = 0; i < n; i++){
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else{
                int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }
};



/*
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        
        int n = arr.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(i == 0) 
                dp[i] = 1;
            else{
                for(int j = 0; j <= i; j++){
                    if(arr[j] < arr[i])
                        dp[i] = max(dp[i], dp[j] + 1);
                    else                    
                        dp[i] = max(dp[i], 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
*/
