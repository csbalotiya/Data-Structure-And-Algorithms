#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fib(int n){  // Complexity 2^n
    if(n == 0 || n == 1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
int main(){
    time_t start, end;
    time(&start);
    int n ; cin>>n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i <= n ;i++){  // Complexity O[n]
        dp[i] = dp[i-1]+dp[i-2];
    }


    cout<<"nth fib.  number is : "<<dp[n]<<"\n";
    time(&end);
    cout<<"Time taken by Dynamic Programming : "<<double(end-start);
    cout<<"\n";

    time(&start);
    cout<<fib(n-1)<<"\n";
    time(&end);
    cout<<"Time taken by Recursion : "<<double(end-start);

    return 0;
}


/*
Dynamic programming is a powerful technique for solving problems that might otherwise appear to be extremely difficult 
to solve in polynomial time.
Dynamic programming works by solving subproblems and using the results of those subproblems to more quickly calculate 
the solution to a larger problem.
*/
