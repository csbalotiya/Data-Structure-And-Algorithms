//https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1#:~:text=Given%20a%20sorted%20array%20A,twice%2C%202%20is%20the%20answer.

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & nums){

    int n = nums.size();
    int ans = 0;
    for(auto i : nums){
        ans ^= i;
    }
    return ans;
}

int main(){
    
    vector<int> nums = {7,2,5,6,6,5,2};
    cout<<solve(nums);
    return 0;
}


