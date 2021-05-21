/*    https://leetcode.com/problems/count-sorted-vowel-strings/

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
*/



#include<bits/stdc++.h>
using namespace std;

int countVowelStrings(int n) {
        int dp[n][5] ;
        for(int i = 0; i < 5; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < n; i++){
            int s = 0;
            for(int k = 0 ; k < 5 ; k++){
                    s += dp[i-1][k];
            }
            for(int  j = 0; j < 5; j++){
               if(j == 0){
                   dp[i][0] = s;
                   continue;
               }
                s -= dp[i-1][j-1];
                dp[i][j] = s;
            }
        }

  /*      for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        } */

        int ans  = 0;
        for(int k = 0 ; k < 5 ; k++){
                ans += dp[n-1][k];
        }

        return ans;
    }

int main(){
    int n ;  cin >> n;
    cout<<countVowelStrings(n);
}
