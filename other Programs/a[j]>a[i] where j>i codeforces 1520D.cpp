/*
Codeforces Round #719 (Div. 3)
Problem:	1520D - Same Differences

link : https://codeforces.com/problemset/problem/1520/D

*/

//Time complexity O[N] 

#include <bits/stdc++.h>
#define ll long long
const int inf = (int)1e9;
//using ll = long long;
using namespace std;
int main(){
    ll T; cin >> T;
    while(T--){
        ll n ;cin >> n;
        map<int,int> mp;
        ll ans = 0, x;
        for(ll i = 0; i < n; i++){
            cin>>x;
            ans += mp[x-i]++;
        }
        cout<<ans<<"\n";
    }

	return 0;
}
