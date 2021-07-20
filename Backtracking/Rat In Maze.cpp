// Rat In Maze problem 

//Time Complexity: O(2^n)
//Space Complexity: O(2^n)

#include <bits/stdc++.h> 
using namespace std;

// Function for checking Current position isSafe ?
bool isSafe(vector<vector<int>> &arr, int x, int y, int n){

    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool RateinMaze(vector<vector<int>> &arr, int x, int y, int n, vector<vector<int>> &sol){
    if(x == n-1 and y == n-1){
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n)){   // Check this position is safe or not
       sol[x][y] = 1;
       if(RateinMaze(arr, x+1, y, n, sol))
                return true;
       if(RateinMaze(arr, x, y+1, n, sol))
                return true;
                
        sol[x][y]= 0;           // backtracking : if Path is not posible make it zero
        return false;
    }
    return false;
}
int main()
{
    int n = 5, m = 5;
    // 0 -> Unsafe  1 -> safe Position
    vector<vector<int>> arr = {
                    {1, 0, 1, 0, 1},
                    {1, 1, 1, 1, 1},
                    {0, 1, 0, 1, 0},
                    {1, 0, 0, 1, 1},
                    {1, 1, 1, 0, 1}};

    // Solution array which shows a possible path by 1.1.1.1...
    vector<vector<int>>sol(n,vector<int>(n, 0));

    bool ans = RateinMaze(arr,0, 0, 5, sol);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                cout<<sol[i][j]<<" ";
        }
        cout<<'\n';
    }
}

/*
Output :
1 0 0 0 0
1 1 1 1 0
0 0 0 1 0
0 0 0 1 1
0 0 0 0 1

*/
