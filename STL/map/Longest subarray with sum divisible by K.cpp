//https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1#
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){
	    unordered_map<int,int>mp;
	    int sum = 0, ans;
	    for(int i = 0; i < n; i++){
	        sum = (((sum + arr[i])%k) + k) %k ;
	        if(sum%k == 0){
	            ans = i+1;
	        }
	        if(mp.find(sum%k) != mp.end()){
	            ans = max(ans, i-mp[sum%k]);
	        }else{
	            mp[sum%k] = i;
	        }
	    }
	  return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
