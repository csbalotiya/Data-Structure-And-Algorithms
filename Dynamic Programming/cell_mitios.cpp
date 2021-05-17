/*
 given a number n find minimum cost to reach to n
 and there are 3 operations
    1. d[i] = dp[i/2] , cost = x
    2. dp[i] = dp[i-1], cost = y
    3. dp[i] = dp[i+1], cost = z

    example n = 8,     m1 = 1->2->4->8 similar others

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//use bottom up dynamic programming
int cell_Mitosis(int n, int x, int y, int z){

    int dp[n+1] = {0};

    for(int i = 2 ;i <= n; i++){
        if(n % 2 == 0){
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        }else{
            dp[i] = min(dp[i-1]+y , dp[(i+1)/2] + x + z);
        }
    }
    return dp[n];
}

int32_t main(){

    int n,x,y,z;
    cin>>n>>x>>y>>z; // 5   2 1 3   output will be 4

    cout<<cell_Mitosis(n,x,y,z);

    return 0;
}
