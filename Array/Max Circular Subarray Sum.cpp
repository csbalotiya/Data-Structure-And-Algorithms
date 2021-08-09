//https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
/*
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int circularSubarraySum(int arr[], int n){
        
       int kmax = INT_MIN,kmin=INT_MAX,curr2=0,curr1=0, tot=0;
       for(int i = 0; i < n; i++){
           tot += arr[i];
           curr1 += arr[i];
           kmax = max(kmax, curr1);
           if(curr1 < 0) curr1 = 0;
           
       }
       for(int i = 0; i < n; i++){
           curr2 += arr[i];
           kmin = min(kmin, curr2);
           if(curr2 > 0) curr2 = 0;
       }
       if( tot == kmin ) return kmax;
       return max((tot - kmin), kmax);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
