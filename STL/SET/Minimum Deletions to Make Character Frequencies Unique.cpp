//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        int ans = 0, c = 0;
        unordered_map<char, int> mp;
        for(char ch : s)    mp[ch]++;
        unordered_set<int> set;
        for(auto x : mp){
            int f = x.second;
            while(set.find(f) != set.end()){
                ans+=1;
                f--;
            }
            if(f > 0)   set.insert(f);
        }
        return ans;
    }
};
