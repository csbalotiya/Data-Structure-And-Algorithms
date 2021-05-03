You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int coinChange(vector<int>& coins, int amount) {

        int n = coins.size()+1 ,m = amount+1;

        int dp[n][m];
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if (i == 0){
                    dp[i][j] = INT_MAX-1;
                    continue;
                }
                if(j == 0){
                    dp[i][j] = 0;
                    continue;
                }

                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j] , dp[i][j-coins[i-1]]+1);
                }else{
                    dp[i][j] = dp[i-1][j];
                }


            }
        }
  }

int main(){
    vector<int>v= {1,2,5};
    int amount = 11;

    cout<<coinChange(v,amount);

    return 0;
}
