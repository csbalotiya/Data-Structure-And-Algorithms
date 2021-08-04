/*https://leetcode.com/problems/subsets-ii/
 Subsets II

Solution
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<multiset<int>> res;
        int n = nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            multiset<int> temp;
            for(int i=0;i<n;i++){
                if((1<<i)&mask)
                    temp.insert(nums[i]);
            }
            res.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto s:res){
            vector<int> temp(s.begin(),s.end());
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>>  res;
        for(int i = 0; i < (1<<n); i++){
            vector<int> ans;
            for(int bit =0; bit < n; bit++){
                if(i&(1<<bit)){
                    ans.push_back(nums[bit]);
                }
            }
            sort(ans.begin(), ans.end());
            res.insert(ans);
        }
        
        vector<vector<int>> r(res.begin(), res.end());

        return r;
    }
};
*/
