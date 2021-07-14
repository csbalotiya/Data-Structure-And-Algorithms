//https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string str) {
        
        map<char, int> mp;
        for(char c : str)
                mp[c] += 1;
        
        string ans = "";
        for(int i = 0; i < order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                int count = mp[order[i]];
                ans += string(count, order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto x : mp){
            int counter = x.second;
            ans += string(counter, x.first);
            mp.erase(x.first);
        }
        
        return ans;
    }
};
