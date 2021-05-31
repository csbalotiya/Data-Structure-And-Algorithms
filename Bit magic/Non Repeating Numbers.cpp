//https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#

//complexity O[n]
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & nums){
    int n = nums.size();
    int ans = nums[0];

    for(int i = 1; i < n; i++){
        ans ^= nums[i];
    }
    int temp = ans & ~(ans - 1);

    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] & temp)
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    cout<<x<<" "<<y<<"\n";

    return -1;
}

int main(){

    vector<int> nums = {11,2,5,6,6,5,2,7};
    cout<<solve(nums)<<"\n";

    return 0;
}


