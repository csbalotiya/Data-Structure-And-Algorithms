//https://leetcode.com/problems/combinations/

/*
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include<bits/stdc++.h>
using namespace std;
void helper(int n, int k, vector<int>& nums, vector<vector<int>>& res, vector<int>& v, int ind){

        // base Case
        if(v.size() == k){
            res.push_back(v);
            return;
        }
        if(v.size() > k)
            return ;

        // Body of Recursion
        for(int i = ind; i < n ;i++){
            if(v.size() <= k){
                v.push_back(nums[i]);
                helper(n, k , nums, res, v, i+1);
                v.pop_back();
            }else{
                break;
            }
        }
        return ;
    }

vector<vector<int>> combine(int n, int k) {

        ios::sync_with_stdio(false);
        cin.tie(0);

        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> v;
        helper(n, k, nums, res, v, 0);

        return res;

    }
int main(){

    int k =2,n = 4;

	vector<vector<int>> result;
	result = combine(n,k);

	for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
	}

	return 0;
}
