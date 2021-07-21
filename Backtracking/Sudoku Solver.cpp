//https://leetcode.com/problems/sudoku-solver/

//Time complexity is O(9^(n*n)).
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char val){

        for(int c = 0; c < 9; c++){     // Check value is in current Row
            if(board[row][c] == val){
                return false;
            }
        }
        for(int r = 0; r < 9; r++){     // Check value is in current Column
            if(board[r][col] == val){
                return false;
            }
        }
        while(row != 0 && row != 3 && row != 6){    // Make 3X3 grid set row
            row--;
        }
        while(col != 0 && col != 3 && col != 6){   // Make 3X3 grid set column
            col--;
        }

        for(int i = row ; i < row+3; i++){            // Check in Sub Board of 3X3
            for(int j = col; j < col+3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            cout<<"\n\nSolved Sudoku looks like : \n";
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    cout<<setw(2)<<board[i][j]<<" ";
                }
                cout<<"\n";
            }
            return ;
        }
        if(col == 9){
            solveSudoku(board, row+1, 0);
            return;
        }
        if(board[row][col] != '.'){
            solveSudoku(board, row, col+1);
        }
        if(board[row][col] == '.'){
             vector<char> nums = {'1' , '2' , '3' , '4' , '5'  , '6' , '7' , '8' , '9'};
            for(auto i : nums){
                if(isValid(board, row, col, i)){
                    board[row][col] = i;
                    solveSudoku(board, row, col+1);
                    board[row][col] = '.';      // Backtracking
                }
            }
        }
    }


int main(){

     vector<vector<char>>board = {{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};


    cout<<"Given Sudoku is : \n";
    for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<setw(2)<<board[i][j]<<" ";
            }
            cout<<"\n";
    }
    solveSudoku(board,0,0);
}
