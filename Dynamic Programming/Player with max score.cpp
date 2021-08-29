/*https://practice.geeksforgeeks.org/problems/player-with-max-score/1/#

Given an array arr of non-negative integers of size N, 2 players are playing a game. In each move, a player chooses an element from either end of the array, and the size of the array shrinks by one. Both players take alternate chances and the game continues until the size of the array becomes 0. Every time a player chooses an array element the array value is added to the player's score. At the end player with maximum score wins.
If player 1 starts the game, you have to predict whether player 1 will win the game or not. Both players will play optimally.
*/
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[1001][1001];
    int helper(int arr[], int i, int j, int n){
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int q1 = arr[i] + min( helper(arr, i+1, j-1, n), helper(arr, i+2, j, n) ); 
        int q2 = arr[j] + min( helper(arr, i, j-2, n), helper(arr, i+1, j-1, n) ); 
        
        return dp[i][j] = max(q1,q2);
    }
    
    bool is1winner(int n,int arr[]) {
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        int ans = helper(arr,0,n-1,n);
        return ans > (sum- ans);       
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends

/*
Example 1:

Input:
N = 3
arr[] = {2,6,3}
Output:
0 
*/
