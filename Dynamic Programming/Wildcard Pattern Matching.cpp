//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1#
/*
The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Example 1:

Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'. 
Example 2:

Input:
pattern = "a*ab"
str = "baaabab"
Output: 0
Explanation: Because of'a' at first position,
pattern and str can't be matched.
*/

class Solution{
  public:
    int wildCard(string pattern,string str){
        
        int n = str.size(), m = pattern.size();
        bool dp[m+1][n+1];
        memset(dp,false,sizeof(dp));
        dp[m][n] = true;
        
        for(int i = m-1; i >= 0; i--){
            if(pattern[i] == '*')
                dp[i][n] = dp[i+1][n];
        }
        
        for(int i = m-1; i >= 0; i--){        
            for(int j = n-1; j >= 0; j--){
                if(pattern[i] == '*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else if(pattern[i] == '?' || pattern[i] == str[j])
                    dp[i][j] = dp[i+1][j+1];
                }
        }    
        return dp[0][0];            
    }
};



// ANOTHER APPROCH
class Solution{
  public:
    int wildCard(string p,string s){
        
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++)
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        
        for(int i = 1; i <= n; i++){
            for(int j = 1;  j <= m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
