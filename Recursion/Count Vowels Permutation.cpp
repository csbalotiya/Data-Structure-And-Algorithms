class Solution {
public:
    static const int mod = 1e9+7;
    unordered_map<string, int> dp;
    long rec(int n, char c){
  
     
        if(dp.find(to_string(n)+","+c) != dp.end()) return dp[to_string(n)+","+c]; 
        
        if(n == 1)
            return 1;
        long res;
        if(c == 'a')
            res = rec(n-1,'e') % mod;
        else if(c == 'e')
            res = (rec(n-1,'a') % mod + rec(n-1,'i') % mod) % mod;
        else if(c == 'i')
            res = (rec(n-1,'a') % mod + rec(n-1,'e')% mod + rec(n-1,'o') % mod + rec(n-1,'u') % mod) % mod;
        else if(c == 'o')
            res = (rec(n-1,'i') % mod + rec(n-1,'u') % mod) % mod;
        else if(c == 'u')
            res = rec(n-1,'a') % mod;
            
        dp.insert({to_string(n)+","+c , res});
        return res % mod;
    }
    
    int countVowelPermutation(int n) {
        ios::sync_with_stdio(false),cin.tie(0);
        long a = rec(n,'a') % mod;
        long e = rec(n,'e') % mod;
        long i = rec(n,'i') % mod;        
        long o = rec(n,'o') % mod;
        long u = rec(n,'u') % mod;

        return (a+e+i+o+u) % mod ;

    }
};
