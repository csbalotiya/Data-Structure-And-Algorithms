//https://leetcode.com/problems/permutations/
/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/


#include<bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>>&res, vector<int>& s ,int l, int r){
        // Base Case
        if(l == r){
            res.push_back(s);
            return ;
        }

        // Body of Recursion
        for(int i = l; i < r ;i++){
                swap(s[i],s[l]);
                helper(res, s, l+1, r);
                swap(s[i],s[l]); // BackTracking step
            }
    }

vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        helper(res, nums, 0, nums.size());

        return res;
    }
int main(){

    vector<int> arr;
    arr = {1,2,3};
	vector<vector<int>> result;
	result = permute(arr);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
