/*
In addition to the two sequences, an additional parameter k was introduced. 
A k-ordered LCS is defined to be the LCS of two sequences if you are allowed 
to change at most k elements in the first sequence to any value you wish to.

5 5 1
1 2 3 4 5
5 3 1 4 2

OUTPUT : 3

LINK :- https://code.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
*/

// Solution by DP memoization using recursion

#include <bits/stdc++.h>
#define ll long long
#define inf 1e9
#define mod 1e7
using namespace std;

ll n,m,a[2001], b[2001];
ll dp[2001][2001][6];

ll f(ll i, ll j, ll k){
    if(i == n || j == m){
        return 0;
    }
    if( dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    ll res = 0;
    if(a[i] == b[j]){
        res = 1 + f(i + 1, j + 1, k);
    }
    else{
        if(k > 0){
            res = 1 + f(i + 1,j + 1, k - 1);  // converted one character
        }
        res = max(res, f(i, j+1, k));
        res = max(res, f(i+1, j, k));

    }
    return dp[i][j][k] = res;

}
int main(){
    memset(dp, -1, sizeof(dp));
    ll k;
    cin>>n>>m>>k;
    for(ll i = 0; i < n; i++){
        cin>>a[i];
    }
    for(ll i = 0; i < m; i++){
        cin>>b[i];
    }
    ll ans = f(0,0,k);
    cout<<ans<<"\n";

   return 0;
}

// Live Free Code Insane
