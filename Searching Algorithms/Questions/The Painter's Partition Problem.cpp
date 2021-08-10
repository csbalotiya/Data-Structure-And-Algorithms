/*
https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  int findFeasible(int arr[], int n, long long limit){
      long long sum = 0;
      int painter = 1;
      for(int i = 0; i < n; i++){
          sum += arr[i];
          if(sum > limit){
              sum = arr[i];
              painter++;
          }
      }
      return painter;
  }
    long long minTime(int arr[], int n, int m)    {

        long long high = accumulate(arr, arr + n, 0ll);
        long long low = *max_element(arr, arr + n);
        long long res = 0ll;
        while(low <= high){
            long long mid = (low + high)/2;
            int painter = findFeasible(arr,n,mid);
            if(painter <= m){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
