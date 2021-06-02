//https://www.codechef.com/problems/MARCHA1

// Find A Subset Sum Of Given Number K 
#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>& nums, int n,int k){

    for(int i = 0; i < (1<<n); i++){
        int temp = 0;
        for(int bit = 0; bit < n; bit++){
            if(i&(1<<bit)){
                temp += nums[bit];
            }
        if(temp == k)
            return "Yes";
        }
    }
    return "No";
}

int main(){

       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int t ; cin>>t;
       while(t--){
           int n,k;
           cin>>n>>k;
           vector<int> nums ;//= {10,15,20,25,30};
           int p;
           for(int i = 0; i < n;i++){
                cin>>p;
                nums.push_back(p);
           }
           cout<<solve(nums, n, k)<<"\n";
       }
       return 0;
}
