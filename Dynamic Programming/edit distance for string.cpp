/*
String Word : emial -> email  {edit distance = 2}

allow perform only 3 operations ; 1.insertion 2.deletion 3.replacement  all have cost = 1

Eg1: make cat -> cut {cost = 1 , replacement('a','u') }
Eg2: make cast -> cat {cost = 1, deletion('s')}
Eg3: make cats ->cast  {cost = 2 , deletion('t') + insertion('t') }
Eg4: make sunday -> saturday {cost = 3, replace('n','r')+ insertion('a') + insertion('t')}
*/
#include <bits/stdc++.h>
#define ll long long//using ll = long long;
const int inf = (int)1e9;
using namespace std;
int dp[100][100] ;
int converterRecursive(string c, string s, int i, int j){
    if(i == c.length()+1 || j == s.length()+1){
        return 0;
    }
    if(c[i] == s[j]){
        return converterRecursive(c, s, i+1, j+1);
    }
    else{

         int q1 = converterRecursive(c, s, i+1, j+1);  // replacement

         int q2 = converterRecursive(c, s, i, j+1);   //insertion

         int q3= converterRecursive(c, s, i+1 ,j);   //deletion

         return  1 + min(q1, min(q2,q3));
    }
}


int converterDP(string c, string s){
    int m = c.length();
    int n = s.length();
    int dp[m+1][n+1] = {{}};
    dp[0][0] = 0;
   
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
	    if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(A[i-1]==B[j-1]){
                dp[i][j]= dp[i-1][j-1];
            }
	    else{
		    int q1 =  dp[i-1][j-1]; //replacement
		    int q2 =  dp[i-1][j]; //deletion
		    int q3 =  dp[i][j-1]; //insertion

		    dp[i][j] = min(q1, min(q2, q3)) + (c[i] != s[j]);
	    }
	}
    }
    return dp[m][n];
}
int main(){
       string c = "sunday";
       string s = "saturday";

         for(int i = 0; i< c.length(); i++){
                for(int j = 0; j < s.length(); j++){
                    dp[i][j] = -1;
                }
         }
        cout<<"Minimum distance calculated by recursion : "<<converterRecursive(c, s, 0 ,0)<<"\n\n";

        cout<<"Minimum distance calculated by Dynamic Programming : "<<converterDP(c, s)<<"\n";

	return 0;
}
