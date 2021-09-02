//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
int Solution::maxProfit(const vector<int> &A) {
    
    int ans = 0, temp = INT_MAX;
    for(int i = 0; i < A.size(); i++){

        temp = min(A[i], temp);
        ans =  max(ans, A[i] - temp);
    }
    return ans;
}
