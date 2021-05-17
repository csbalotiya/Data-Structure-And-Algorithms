//  https://www.codechef.com/problems/CD1IT4  
 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int>
int solve(vector<vector<int>>& grid ,int m, int n){

    vector<vi> dp(m,vi(n,0));
    for(int i = 0; i < n; i++){
		if(grid[0][i]){
			dp[0][i] = 1;
		}
		else
			break;
	}

	for(int i = 0; i < m; i++){
		if(grid[i][0]){
			dp[i][0] = 1;
		}
		else
			break;
	}

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(grid[i][j])
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

  /*  for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;*/

    return dp[m-1][n-1];
}
int main(){

	int m,n,p,x,y;
	cin>>m>>n>>p;

	vector<vector<int>> dp(m,vector<int>(n,1));


	for(int i =0; i < p; i++){
            cin>>x>>y;
        dp[x-1][y-1] = 0;
	}
 /*   for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl; */
    cout<<solve(dp,m,n);
	return 0;
}

/*
input:
4 3 2
3 3
3 1

Output:
2
*/
