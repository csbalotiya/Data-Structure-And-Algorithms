//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

//https://leetcode.com/problems/jump-game-ii/

//this is GFG Solution
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int jumps = 0, farthest = 0, currEnd = 0;
        for(int i=0;i<n-1;i++)
        {
            farthest = max(farthest, i + arr[i]);
            if(farthest >= n-1)
                return 1 + jumps;
            
            if(i == farthest)
                return -1;
            
            if(i == currEnd)
            {
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
