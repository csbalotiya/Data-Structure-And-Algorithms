//https://www.geeksforgeeks.org/count-minimum-swap-to-make-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

/*Time Complexity: O(n2) 
Auxiliary Space: O(1)*/
int solve(string s){
    int n = s.length();
    int res = 0;

    for(int i = 0; i < n/2; i++){
        int l = i, r = n-l-i;
        while(l < r){
            if(s[l] == s[r]){
                break;
            }else{
                r--;
            }
        }

        if(l == r){
            return -1;
        }
        for(int j = r; j < n-l-1; j++){
            swap(s[j], s[j+1]);
            res += 1;
        }
    }
    return res;
}


int main(){

    string s = "aabcb";
    int ans1 = solve(s);

    reverse(s.begin(), s.end());
    int ans2 = solve(s);
    cout<<ans1<<" "<<ans2<<"\n";
    cout<<max(ans1, ans2);
}
/**
Input: aabcb 
Output: 3 
Explanation: 
After 1st swap: abacb 
After 2nd swap: abcab 
After 3rd swap: abcba
Input: adbcdbad 
Output: -1 
*/
