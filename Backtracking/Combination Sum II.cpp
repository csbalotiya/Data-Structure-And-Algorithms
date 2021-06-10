//https://leetcode.com/problems/combination-sum-ii/
/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>& candidates, int target,set<vector<int>>& res, vector<int>& v, int ind){

        //base Case
        if(target == 0){
            res.insert(v);
            return;
        }
        if(target < 0 || ind == candidates.size())
            return ;

        // Body of Recursion
        for(int i = ind; i < candidates.size(); i++){

            if(candidates[i] <= target){
                v.push_back(candidates[i]);
                helper(candidates, target- candidates[i], res, v, i+1);
                v.pop_back(); // back tracking
            }else{
                break;
            }
        }
        return ;
    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        set<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, res, v, 0);

        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
int main(){

	vector<int> candidates ;
	candidates = {10,1,2,7,6,1,5};
	int target = 8;

	vector<vector<int>> result;
	result = combinationSum2(candidates , target);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
