/* Dynamic Programming C++ implementation of LCS problem 

complexity is O[n*m]   */
#include<bits/stdc++.h>
using namespace std;
int lcs( string X, string Y, int m, int n ){
	int DP[m + 1][n + 1];
	int i, j;
	for (i = 0; i <= m; i++){
		for (j = 0; j <= n; j++){
		if (i == 0 || j == 0)
			DP[i][j] = 0;
		else if (X[i - 1] == Y[j - 1])
			DP[i][j] = DP[i - 1][j - 1] + 1;
		else
			DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	return DP[m][n];
}
int main(){
	string X = "AABCDS";
	string Y = "CSACSD";
	int m = X.length();
	int n = Y.length();
	cout << "Length of LCS is "<< lcs( X, Y, m, n );
	return 0;
}
