#include <bits/stdc++.h>
using namespace std;
#include <string.h>
#include <iostream>
using namespace std;

string helper(string& s, int l , int r){
            int length = l==r ?-1:0;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                l-=1;
                r+=1;
                length += 2;
            }
            return s.substr(1+l,length);
        }
string longestPalindrome(string s) {
        string ans = "",temp;
        for(int i = 0 ; i < s.length() ; i++){
            temp = helper(s,i,i);
            if(ans.length() < temp.length()){
                ans = temp;
            }
            temp = helper(s,i,i+1);
            if(ans.length() < temp.length()){
                ans = temp;
            }
        }
        return ans;
    }


int main(){
    cout<<longestPalindrome("babcbabcbaccba")<<endl;
    cout<<longestPalindrome("mqxqqx")<<endl;
    cout<<longestPalindrome("abc")<<endl;
    cout<<longestPalindrome("abcbabc")<<endl;

}
