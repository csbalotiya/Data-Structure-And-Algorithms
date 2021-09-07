
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int> > &A) {
    int m = A.size(),n = A[0].size(),ans=INT_MIN;
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));// Stores the sums of submatrices starting at the index and ending at last element
	for(int i=m-1;i>=0;i--){ // Start iteration at last element and move left and up
		for(int j=n-1;j>=0;j--){ // Sum of sub matrix includes current element
			dp[i][j]=A[i][j];
		        dp[i][j] += dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1]; // ans will be the submatrix having largest sum
			ans = max(ans,dp[i][j]);}}
	return ans;
}
int main(){
    vector<vector<int>>a = {{1,2,-3},
                            {-3,1,-6},
                            {1,2,3}};
    cout<<solve(a);
}
