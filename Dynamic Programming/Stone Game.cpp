/*https://leetcode.com/problems/stone-game/

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
*/

class Solution {
public:
  int t[501][501];
   int helper(vector<int>&piles,int start,int end){
       if(start>=end) return 0;
     if(t[start][end]!=-1) return t[start][end];
       return t[start][end]=max(piles[start]+helper(piles,start+1,end-1),
                                piles[end]+helper(piles,start+1,end-1));
   }
    bool stoneGame(vector<int>& piles) {
      int sum=0;
      for(auto x:piles) sum+=x;
      memset(t,-1,sizeof(t));
       return helper(piles,0,piles.size()-1)>sum/2;    
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(); 
        vector<vector<int>> dp(n, vector<int>(n)); 
        for (int i = n-1; i >= 0; --i) 
            for (int j = i; j < n; ++j) 
                if (i == j) dp[i][j] = piles[i]; 
                else dp[i][j] = max(piles[i] + dp[i+1][j], piles[j] + dp[i][j-1]); 
            
        return dp[0][n-1] > 0; 
    }
};
