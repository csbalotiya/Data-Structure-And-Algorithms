//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s)   { 
         int n = s.size();
        string ans = "";
        int j = n;
        for(int i = n-1; i >=0 ; i--){
            if(s[i]== '.'){
                ans += s.substr(i+1,j-i-1);
                //cout<<i<<"  "<<j<<"   "<<s.substr(i+1,j+1)<<"\n";
                j = i;
                ans+='.';
            }
            if(i == 0){
                ans += s.substr(i,j-i);
            }

        }
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
