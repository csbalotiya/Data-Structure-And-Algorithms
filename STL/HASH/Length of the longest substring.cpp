//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1#

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        
        int hash[256];
        memset(hash,-1,sizeof(hash));
        int mx = 0, mn =0, p = 0;
        for(int i = 0; i < S.size(); i++){
            p = max(p, hash[S[i]] + 1);
            mx = max(mx, i-p+1);
            hash[S[i]] = i;
        }
        return mx;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends
