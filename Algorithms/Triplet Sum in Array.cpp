//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int x){
    
        sort(A,A+n);
        for(int i = 0; i < n-2; i++){
                int l = i+1, r = n-1, q = x-A[i];
                while(l < r){
                    if(A[l]+A[r] == q)
                        return true;
                    else if(A[l]+A[r] < q){
                        l++;
                    }else{
                        r--;
                    }
                }
        } 
        return false;
    }
   
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
