// N Queen problem

// complexity  O(N!)


#include <bits/stdc++.h>
using namespace std;

// Function for checking Current position isSafe ?
bool isSafe(vector<vector<char>> &arr, int x, int y, int n){

    // column
    for(int c = 0; c < x; c++){
        if(arr[c][y] == 'Q')
            return false;
    }

   // Diagonal
   int row = x, col = y;
   while(row >= 0 && col >= 0){     // Left Diagonal
        if(arr[row][col] == 'Q')
            return false;
        row--;
        col--;
   }

   row = x;
   col = y;
   while(row >= 0 && col < n){      //Right Diagonal
        if(arr[row][col] == 'Q')
            return false;
        row--;
        col++;
   }
   return true;
}

bool nQueen(vector<vector<char>> &board, int x, int n){
    if(x >= n){
        return true;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(board, x, col, n)){
            board[x][col] = 'Q';

            if(nQueen(board,x+1,n)){
                return true;
            }
            board[x][col] = '_'; // BACKTRACKING
        }
    }
    return false;
}

int main()
{
    int n = 4;
    vector<vector<char>>board(n,vector<char>(n, '_'));

    bool ans = nQueen(board, 0, n);
    if(ans){
        cout<<"There is a Solution\n";
        cout<<'\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    cout<<board[i][j]<<" ";
            }
            cout<<'\n';
        }
    }else{
        cout<<"There is a No Solution\n";
    }
}

/*
For N = 4 ;
Output :
_ Q _ _
_ _ _ Q
Q _ _ _
_ _ Q _

*/
