// C++ program to get maximum sum subarray removing at-most k element
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int solve(int arr[], int i, int j){

    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == 0)
        return dp[i][j] = max(0 ,arr[i]);

    int x = max(0, arr[i]+ solve(arr,i-1,j));

    if(j == 0)
        return dp[i][j] = x;

    int y = solve(arr, i-1, j-1);
    return dp[i][j] = max(x,y);
}

int main(){

    int arr[] = { -2, 1, 3, -2, 4, -7, 20 }; //26
//	int arr[] = {1,2,3,-4,-5,-6,1,-2,8}; // 8

	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 1;

	memset(dp, -1, sizeof(dp));
	solve(arr, n, k);

    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++)
            ans = max(ans, dp[i][j]);
    }
    if (*max_element(arr, arr + n) < 0) {
        ans = *max_element(arr, arr + n);
    }
	cout<<ans;

	return 0;
}

