/* Friend pairing problem
Examples:

Input  : n = 3
Output : 4
Explanation:
{1}, {2}, {3} : all single
{1}, {2, 3} : 2 and 3 paired but 1 is single.
{1, 2}, {3} : 1 and 2 are paired but 3 is single.
{1, 3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1, 2} and {2, 1} are considered same.
link  : https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
*/

// Complexity O[N]
#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int solution(long long int n){
        int dp[n];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(long long int i = 3; i <= n; i++)
            dp[i] = (dp[i-1] + (i-1) * dp[i-2]) % 1000000007;

        return dp[n] ;

}
int main(){
    fast()
    long long int n;  cin>>n;

    cout<<solution(n)<<endl;
    return 0;
}
