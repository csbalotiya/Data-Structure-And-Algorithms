//https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            if(mp1.find(s[i]) != mp1.end()){
                if(mp1[s[i]] != t[i])
                    return false;
            }else{
                mp1[s[i]] = t[i];
            }       
            
             if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i])
                    return false;
            }else{
                mp2[t[i]] = s[i];
            }   
        }

        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        vector<int> m1(256, -1);
        vector<int> m2 (256, -1);
        
        for(int i=0; i< s.length(); i++){
            if(m1[s[i]]!=m2[t[i]]) return false;
            m1[s[i]]=i;
            m2[t[i]]=i;
        }
        return true;
    }
};
