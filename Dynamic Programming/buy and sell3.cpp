//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       /* int ans, n = prices.size();
        if(n == 0) return 0;
        vector<int> left(n), right(n);
        int leftmin = prices[0], rightmax = prices[n-1];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], prices[i] - leftmin);
            leftmin = min(leftmin, prices[i]);
        }
    
        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], rightmax - prices[i]);
            rightmax = max(rightmax, prices[i]);
        } 
        
        for(int i = 1; i < n; i++){
          ans = max(left[i]+right[i], ans);
        }
        return ans;*/
        
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t1Cost = INT_MAX, t2Cost = INT_MAX;
        int t1Prof = 0, t2Prof = 0;
        for(int price : prices){
            t1Cost = min(t1Cost, price);
            t1Prof = max(t1Prof, price - t1Cost);
            t2Cost = min(t2Cost, price - t1Prof);
            t2Prof = max(t2Prof, price - t2Cost);
        }
        return t2Prof;
    }
};
