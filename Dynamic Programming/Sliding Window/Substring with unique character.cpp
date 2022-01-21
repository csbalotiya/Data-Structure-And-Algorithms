#include <bits/stdc++.h>
using namespace std;

string longestUniqueSubstring(string str, int n){

    int i, st = 0, currlen, maxlen = 0, start;
    unordered_map<char, int> pos;

    pos[str[0]] = 0;
    for (i = 1; i < n; i++) {
        if (pos.find(str[i]) == pos.end())
            pos[str[i]] = i;
        else {
            if (pos[str[i]] >= st) {
                currlen = i - st;
                if (maxlen < currlen) {
                    maxlen = currlen;
                    start = st;
                }
                 st = pos[str[i]] + 1;
            }
            pos[str[i]] = i;
        }
    }
    if (maxlen < i - st) {
        maxlen = i - st;
        start = st;
    }
    return str.substr(start, maxlen);
}

int main(){

    cout<<longestUniqueSubstring("abcdas", 6)<<endl;
    cout<<longestUniqueSubstring("abcdeas",7);
}
