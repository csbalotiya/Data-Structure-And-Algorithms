// By BFS 
//https://leetcode.com/problems/number-of-islands/

/*
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid,int n,int m,int i, int j){

    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

    grid[i][j] = 0;
    return 1 +helper(grid,n,m,i-1,j) + helper(grid,n,m,i,j-1) + helper(grid,n,m,i+1,j) + helper(grid,n,m,i,j+1);
}

int main(){
    vector<vector<int>> grid;
    grid = {{1,1,0,0,0},
            {1,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,1}
            };

    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j])
            ans = max(ans, helper(grid,n,m,i,j));
        }
    }
    cout<<ans;
    return 0;
}

