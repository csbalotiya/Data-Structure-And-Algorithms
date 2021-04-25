#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s = "ADOBECODEBANCC";
    string t = "ACBC";
    int flag[256] = {0};
    int n = s.length();
    int m = t.length();
    
    for(int i = 0 ; i < m ;i++){
            flag[t[i]] += 1;
    }
    int start = 0 ,i = 0 ,ans = INT_MAX ,count = t.size();
    for(int j = 0 ; j < n;j++)
        {
            if(flag[s[j]] > 0)            count--;
            flag[s[j]]--;

            while(count == 0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    start = i;
                }
                flag[s[i]]++;
                if(flag[s[i]] > 0){
                    count++;
                }
                i++;
            }
        }
    cout<<s.substr(start , ans);


  return 0;
}
