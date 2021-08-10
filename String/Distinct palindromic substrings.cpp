//https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1#
#include <bits/stdc++.h>
using namespace std;

void helper(string& s, int l , int r, auto &set){
            int length = l==r ?-1:0;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                set.insert(s.substr(l,r-l+1));
                l-=1;
                r+=1;
                length += 2;
            }
            set.insert(s.substr(1+l,length));
        }

int Palindromes(string s) {
        unordered_set<string> set;
        string ans = "",temp;
        for(int i = 0 ; i < s.length(); i++){
            helper(s,i,i,set);
            helper(s,i,i+1,set);
        }
/*      for (auto i : set)
        		cout << i << " ";*/
        return set.size()-1; //remove " "
    }


int main(){
    cout<<Palindromes("abaaa")<<endl;
    cout<<Palindromes("geek")<<endl;
    cout<<Palindromes("abc")<<endl;
    cout<<Palindromes("abcbabc")<<endl;

}
