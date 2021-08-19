//https://leetcode.com/problems/reorganize-string/
class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        int n = s.size();
        priority_queue<pair<int, char>> p;
        map<char,int> m;
        for(auto c: s)     m[c]++;
       
        for(auto x : m){
            pair<int, char>t(x.second, x.first);
            p.push(t);
        }
        int a,b;
        char ch1,ch2;
        while(!p.empty()){
            pair<int,char> x = p.top();
            ans+=x.second;
            a = x.first-1;
            ch1 = x.second;
            p.pop();
            if(!p.empty()){
                pair<int,char> y = p.top();
                ans+=y.second;
                b = y.first-1;
                ch2 = y.second;
                p.pop();
            }
            if(a>0) p.push({a,ch1});
            if(b>0) p.push({b,ch2});
        }
      
        bool f = false;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]){
                f = true;
                break;
            }
        }
        if(f) return "";
        return ans;
    }
};
