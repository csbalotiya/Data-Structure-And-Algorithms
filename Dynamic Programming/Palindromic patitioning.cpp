//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#
class Solution{
public:
    int dp[501][501];
    bool pali(string s, int i, int j){
        while(i <= j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    
    int helper(string s, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= j || pali(s,i,j)){
            dp[i][j] = 0;
            return 0;
        }
        
        int ans = INT_MAX;
        for(int ind = i; ind < j; ind++){
            if(pali(s,i,ind)){
                int temp = 1 + helper(s,ind+1,j);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str){
       int n = str.size();
       memset(dp,-1,sizeof(dp));
       return helper(str,0,n-1);
    }
};
