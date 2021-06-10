//https://leetcode.com/problems/combination-sum-iii/
/*
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
*/

#include<bits/stdc++.h>
using namespace std;
void helper(int k, int target,vector<int>& nums, vector<vector<int>>& res, vector<int>& v, int ind){

        if(target == 0 && v.size() == k){
            res.push_back(v);
            return;
        }
        if(target < 0 || ind == nums.size())
            return ;

        // Body of Recursion
        for(int i = ind; i < nums.size(); i++){
            if(nums[i] <= target){
                v.push_back(nums[i]);
                helper(k, target - nums[i], nums, res, v, i+1);
                v.pop_back();
            }else{
                break;
            }
        }
        return;
    }

vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>nums;
        for(int i = 1; i < 10; i++){
            nums.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> v;
        helper(k, n, nums, res, v, 0);

        return res;
    }
int main(){

    int k =3,n = 9;

	vector<vector<int>> result;
	result = combinationSum3(k,n);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
