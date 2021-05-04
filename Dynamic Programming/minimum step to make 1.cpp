Quesion : Minimum steps required to make  a number 1 . Steps that only apply are:
                                      1. divide by 2
                                      2. divide by 3
                                      3. substact by 1 / add -1



// Complexity O[n]
#include <bits/stdc++.h>
#define ll long long
const int inf = (int)1e9;
using namespace std;

int main(){
    time_t start, end;
    time(&start);

    int n ; cin>>n;
    int dp[n+1];
    dp[0] = 0;  dp[1] = 0;
    dp[2] = 1;  dp[3] = 1;

    for(int i = 4 ; i <= n ;i++){
        int q1 = inf;
        int q2 = inf;
        int q3 = inf;

        if(i % 3 == 0) q1= 1+ dp[i/3];
        if(i % 3 == 0) q2= 1+ dp[i/2];
        q3= 1+ dp[i-1];

        dp[i] = min(q1,min(q2,q3));
    }
    cout<<"Minimum steps required is : "<<dp[n]<<"\n";

    time(&end);
    cout<<"Time taken by Dynamic Programming : "<<double(end-start)<<"\n";

    return 0;
}
