//https://leetcode.com/problems/permutations-ii/
/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<bits/stdc++.h>
using namespace std;
void helper(set<vector<int>>& res, vector<int>& nums ,int l, int r){

        if(l == r){      // Base Case
            res.insert(nums);
        }else{
            for(int i = l; i < r; i++){
                swap(nums[i], nums[l]);
                helper(res, nums, l+1, r);
                swap(nums[i], nums[l]);
            }
        }
    }

vector<vector<int>> permuteUnique(vector<int>& nums) {

        set<vector<int>> res;
        helper(res, nums, 0, nums.size());

        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
int main(){

    vector<int> arr;
    arr = {1,2,3};
	vector<vector<int>> result;
	result = permuteUnique(arr);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
