// Time complexity O[n]
// Space Complexity O[1]
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int arr[] = {0,1,0,1,0,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = 0 , k = 2;
    int count0 = 0;
    int l = 0;
    for(int i = 0 ; i < n ;i++){
        if(arr[i] == 0){
            count0 += 1;
        }

        while(count0 > k){
            if(arr[l] == 0)
                count0-=1;
            l+=1;
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans;

  return 0;
}
