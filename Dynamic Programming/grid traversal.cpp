//Minimum cost by traversing grid from  left top corner to right bottom corner

#include <bits/stdc++.h>
using namespace std;

int minCostRecursive(int grid[100][100] , int n , int i , int j , int total){
    if(i == n-1 && j == n-1){
        return total+grid[n-1][n-1];
    }
    if(i == n-1){
        return minCostRecursive( grid , n , i , j+1 , total+grid[i][j]);
    }
    if(j == n-1){
        return minCostRecursive( grid , n , i+1 , j , total+grid[i][j]);
    }

    int p1 = minCostRecursive( grid , n , i+1 , j , total+grid[i][j]);
    int p2 = minCostRecursive( grid , n , i , j+1 , total+grid[i][j]);


    return min(p1 , p2);
}



int minCost( int grid[][100] , int m ,int n){

    int dp[100][100] = {};
    dp[0][0]  = grid[0][0];

    for(int c = 1 ; c < n ; c++){
        dp[0][c] = dp[0][c-1] + grid[0][c];
    }

    for(int r = 1 ; r < m ; r++){
        dp[r][0] = dp[r-1][0] + grid[r][0];
    }

    for(int r = 1; r < m ;r++){
        for(int c = 1 ; c < n ; c++){
            dp[r][c] = min(dp[r-1][c] , dp[r][c-1]) + grid[r][c];
        }
    }
    for(int r = 0; r < m ;r++){
        for(int c = 0 ; c < n ; c++){
                cout<<setw(3)<<dp[r][c]<<" ";
        }cout<<"\n";
    }

    cout<<"Minimum cost from left top corner to right bottom corner by dp is  : ";
    return dp[m-1][n-1];
}


int main() {
   
    int n = 3;
    int grid[100][100] = {{1,2,3},
                      {4,8,2},
                      {1,5,3}};

    cout<<"Minimum cost from left top corner to right bottom corner bu recursion is  : "<<minCostRecursive(grid ,n ,0 , 0 , 0)<<"\n\n";
    cout<<minCost(grid , n , n);


	return 0;
}
