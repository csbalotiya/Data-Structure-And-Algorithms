#include <iostream>
using namespace std;
int max(int a, int b){
	return (a > b) ? a : b;
}
// Returns the maximum value that can be put in a DPnapsacDP of capacity W
int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	int DP[n + 1][W + 1];
	// Build table DP[][] in bottom up manner
	for (i = 0; i <= n; i++){
		for (w = 0; w <= W; w++){
			if (i == 0 || w == 0)
				DP[i][w] = 0;
			else if (wt[i - 1] <= w)
				DP[i][w] = max(val[i - 1]+ DP[i - 1][w - wt[i - 1]],DP[i - 1][w]);
			else
				DP[i][w] = DP[i - 1][w];
		}
	}
	return DP[n][W];
}
int main(){
	int val[] = { 10, 15, 40 };
	int wt[] = { 1, 1, 3 };
	int W = 6;
	int n = sizeof(val) / sizeof(val[0]);
	cout<<knapSack(W, wt, val, n);
	return 0;
}
