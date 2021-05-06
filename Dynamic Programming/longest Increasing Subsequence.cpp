/*
Eg : [ 10, 22, 9, 33, 21, 50, 41, 60, 80 ]

for this longest increasing subsequence is length 6
              10 -> 22 -> 33 -> 50 -> 60 ->80

*/

#include <bits/stdc++.h>
#define ll long long//using ll = long long;
const int inf = (int)1e9;
using namespace std;
// Longest Increasing Subsequence

int DP(vector<int>& nums, int n){

    int dp[n] ;
    //base case
    for(int i = 0; i < n; i++)dp[i] = 1;

    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int j = i+1; j < n; j++){
            if(nums[j] > nums[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }
  /*  for(int i = 0; i < n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;  */

    return dp[n-1];
}


int main(){

  vector<int> nums = {50, 3, 10, 7, 40, 50};   // op = 4
  
  //{3,2}; op = 1
  
  //{3, 10, 2, 1, 20};  op = 3
 
  //{10, 22, 9, 33, 21, 50, 41, 60, 80}; op = 6

  cout<<"Minimum distance calculated by Dynamic Programming : "<<DP(nums, nums.size())<<"\n";

	return 0;
}
