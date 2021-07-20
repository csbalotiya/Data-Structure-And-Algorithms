// Night tour problem
//There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8N^2).
#include <bits/stdc++.h>
using namespace std;

int N;
int dx[8]= { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8]= { 1, 2, 2, 1, -1, -2, -2, -1 };
int board[100][100];

bool isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool Knight(int x, int y, int movei){

    int k, nextX, nextY;
    if(movei == N*N)
        return true;

    for(k = 0; k < 8; k++){
        nextX = x + dx[k];
        nextY = y + dy[k];
        if(isSafe(nextX, nextY)){
            board[nextX][nextY] = movei;
            if(Knight(nextX, nextY, movei+1))
                return true;
            else
                board[nextX][nextY] = -1;
        }
    }
    return false;
}

int main(){

    N = 8;
    memset(board, -1, sizeof(board));
    board[0][0] = 0;

    if(!Knight(0,0,1)){
        cout<<"There is No Solution ";
        exit(0);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<" "<< setw(3)<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

}
