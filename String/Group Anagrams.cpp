/*https://leetcode.com/problems/group-anagrams/
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> sol;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp.count(temp)==0) {
                mp[temp]=sol.size();
                sol.push_back({strs[i]});
            }
            else {
                int ind = mp[temp];
                sol[ind].push_back(strs[i]);
            }
        }
        return sol;
    }
};


//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& list) {
        vector<vector<string> > ans;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < list.size(); i++){
            string temp = list[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(list[i]);
        }
        for(auto x: mp)
            ans.push_back(x.second);
            
        return ans;
    }
};
