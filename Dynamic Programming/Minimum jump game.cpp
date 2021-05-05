Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
 
Example 1:
          Input: nums = [2,3,1,1,4]
          Output: 2
          Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
          Input: nums = [2,3,0,1,4]
          Output: 2
            
// Bottom up approach 
int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        for(int i=1;i<n;i++)
            dp[i]=INT_MAX;

        dp[0]=0;
        for(int i=1;i<n;i++ )
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]!=INT_MAX && j+nums[j]>=i)
                {
                    dp[i]=min(dp[i],dp[j]+1);

                }
            }
        }
        return dp[n-1];
}
/* Top down recursively approach
 long fun(vector<int>&arr , int i , int n , vector<int>&dp){
        if(i >= n-1)
            return 0;

        if(i + arr[i] >= n-1)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        long temp = INT_MAX;
        for(int j = 1 ; j <= arr[i] ; j++){
            temp = min(temp ,1 + fun(arr , i+j , n ,dp));
        }
        return dp[i] = temp;
    }
   
    int jump(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return fun(arr , 0 , n , dp);
    }*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums = {2,3,1,1,4};
    cout<<jump(nums);
	return 0;
}
