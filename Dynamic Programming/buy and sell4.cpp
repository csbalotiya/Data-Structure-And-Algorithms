//https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int dp[1001][1001][2];
    int solve(vector<int>&arr, int i, int k, bool stockWithMe){
        if(i>=arr.size())
            return 0;
        if(k<=0)
            return 0;
        if(dp[i][k][stockWithMe]!=-1)
            return dp[i][k][stockWithMe];
        if(stockWithMe){
            //I am having a stock with me, so either I sell or do nothing
            int m=max(arr[i]+solve(arr,i+1,k-1,0) , solve(arr,i+1,k,1));
            return dp[i][k][stockWithMe]=m;      
        }
        if(!stockWithMe){
            //I am not having a stock with me, so either I buy or do nothing
            int m=max(-arr[i]+solve(arr,i+1,k,1) , solve(arr,i+1,k,0));
            return dp[i][k][stockWithMe]=m;
        }
        return 0;
    }
    
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k,0);
    }
};
