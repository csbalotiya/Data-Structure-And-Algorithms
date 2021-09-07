#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    int sIndex = 0, tIndex = 0, start = -1;
    int m = s.length(), n = t.length(), minLength = m;
    string ss = s, tt = t;
    while (sIndex < m) {
        if(ss[sIndex] == tt[tIndex]) { // char match
            if(++tIndex == n) { // end
                int end = sIndex + 1;

                while(--tIndex >= 0) {
                    while(ss[sIndex--] != tt[tIndex]);
                }
                sIndex++;
                tIndex++;

                // record
                if (end - sIndex < minLength) {
                    minLength = end - sIndex;
                    start = sIndex;
                }
            }
        }
        ++sIndex;
    }
    return start == -1 ? "" : s.substr(start, minLength);
}
int main(){
    string s= minWindow("abcdebdde","bde");  //op : bcde
    cout << s << endl;

    return 0;
}
