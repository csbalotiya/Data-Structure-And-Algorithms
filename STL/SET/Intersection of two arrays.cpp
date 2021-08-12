//https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:

    int NumberofElementsInIntersection (int a[], int b[], int n, int m ){
        
        unordered_set<int> set;
        for(int i = 0; i < n; i++){
             set.insert(a[i]);
        }
        
        int c = 0;
        for(int j = 0; j < m; j++){
            if(set.find(b[j]) != set.end()){
                c++;
                set.erase(b[j]);
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
		Solution ob;
		cout << ob.NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
}  // } Driver Code Ends
