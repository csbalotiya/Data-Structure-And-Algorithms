/*
https://leetcode.com/problems/divisor-game/

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: n = 2
Output: true
*/

class Solution {
public:
    vector<int> dp;
    bool recursion(int n){
        if(n==1)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        if(!recursion(n-1))
            return dp[n] = 1;
        
        return dp[n] = 0;
    }
    
    bool divisorGame(int n) {
        dp.resize(n+1, -1);
        return recursion(n);
    }
};
