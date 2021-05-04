You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
  
 //complexity O[amount*coins]
  
  #include <bits/stdc++.h>
#define ll long long
using namespace std;

int change(int amount, vector<int>& coins) {

        int c = amount+1;
        int r = coins.size()+1;
        int dp[r][c];

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    if(j%coins[i] == 0)
                        dp[i][j]= 0;
                    else
                        dp[i][j] = 0;
                    continue;
                }

                if(coins[i-1] <= j){                              // if amount is less then that way make by this coin + way by amount - current coin by pre find way
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];  
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    /*     for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
            } */

        return dp[r-1][c-1];
    }

int main(){
            vector<int> v = {1,2,5};
            int amount = 5;
            cout<<change(amount , v)<<"\n";
    return 0;
}
