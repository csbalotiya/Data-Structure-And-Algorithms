/*
Give a rod of length of n where each length have different sell price find maximum profit can be get by selling this rod


0|....1|.....2|....3|.....4|     values = {2,3,2,5} for 0 len cut it price is zero
*/
#include <bits/stdc++.h>//#define ll long long
const int inf = (int)1e9;
using namespace std;
vector<int>dp(100,-1);
int rodcutRec(int arr[] , int n ){

    if(n == 0)  return 0;
    if(dp[n] != -1) {
            return dp[n];
    }

    int best = 0;
    for(int i = 1 ; i <= n; i++){
        int netprofit = rodcutRec(arr,n-i) + arr[i];
            best = max(best , netprofit);
    }
    dp[n] = best;
    return best;
}

int rodcutBU(int arr[] , int n){

    int dp[100] = {};
    for(int i = 1; i <= n; i++){
        int best = 0;
        for(int j = 1; j <= i; j++){                // second loop check for all iteration that give maximum profits ans store max in dp table
                best = max(best , arr[j]+dp[i - j]);
        }
        dp[i] = best;
    }
    return dp[n];

}


int main(){         time_t start , end;    time(&start);

    int arr[100];
    int n ; cin >> n;                    // int n =4;      arr = {0,2,3,2,5};
    for(int i = 1; i <= n ;i++){        //int n =4    arr = {0,1,3,2,5};
        cin>>arr[i];                    // first index set 0 for cut at zero
    }

    cout<<"Answer by Recursive memoization is : "<<rodcutRec(arr ,n )<<"\n\n";

    cout<<"Answer by Bottom Up Approch is : "<<rodcutBU(arr ,n )<<"\n\n";
    time(&end);   cout<<"Time taken by Dynamic Programming : "<<double(end-start)<<"\n";

    return 0;
}
