//https://leetcode.com/problems/combination-sum/
/*
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
*/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& candidates, int target,vector<vector<int>>& res, vector<int>& v, int ind ){
        // base Case
        if(target == 0){
            res.push_back(v);
            return;
        }

        if(target < 0)
            return ;

        // body of recursion
        for(int i = ind; i < candidates.size(); i++){

            if(candidates[i] <= target){
                v.push_back(candidates[i]);
                helper(candidates, target - candidates[i], res, v, i);
                v.pop_back();  // backtracking step
            }else{
                break;
            }
        }
        return ;

    }
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, res, v, 0);

        return res;
    }
int main(){

	vector<int> candidates ;
	candidates = {2,3,6,7};
	int target = 7;

	vector<vector<int>> result;
	result = combinationSum(candidates , target);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
