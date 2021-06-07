//https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n];
        memset(dp,  100 , sizeof(dp));
        dp[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j <= i + nums[i]; j++){
                if(j >= n)
                    break;
                
                dp[j] = min(dp[j],dp[i] + 1);
            }
        }
        
        for(int i = 0; i < n; i++)
            cout<<dp[i]<<" ";
        
        return dp[n-1];
    }
};
