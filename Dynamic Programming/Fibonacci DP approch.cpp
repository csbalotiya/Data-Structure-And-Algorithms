#include<bits/stdc++.h>
using namespace std;
int dp[100] ;

int fibRecursive(int n){  // Recursion
        if(n==0 || n==1)
            return n;
        else
            return fibRecursive(n-1)+fibRecursive(n-2);
}

int fib_DP(int n){  // Dynamic programming with memoization
    if(dp[n]==-1){
        if(n <= 1)
            dp[n]=n;
        else
            dp[n]=fib_DP(n-1)+fib_DP(n-2);
    }
    return dp[n];
}

int fib_BottomUp(int n){  // Bottom UP Approch

    int dp[100];
    dp[0] = 0; dp[1] =1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n; cin>>n;   // take big integer like 45 and show execution time difference .

    for(int i=0; i < 100;i++){
        dp[i]=-1;
    }

    cout<<"Nth fibonacci number by Recursion : "<<fibRecursive(n-1)<<"\n";

    cout<<"Nth fibonacci number by Dynamic Programming with memoization : "<<fib_DP(n-1)<<"\n";

    cout<<"Nth fibonacci number by Dynamic Programming Bottom Up approch : "<<fib_BottomUp(n-1);

    return 0;
}
