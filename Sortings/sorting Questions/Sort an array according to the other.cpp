//https://practice.geeksforgeeks.org/problems/relative-sorting4323/1#
// Example of map , map is always sorted according the key.

class Solution{
    public:
    vector<int> sortA1ByA2(vector<int> A1, int n, vector<int> A2, int m) {
        
        vector<int> v;
        map<int, int>mp;
        
        for(int i = 0; i < n ; i++){
            mp[A1[i]]++;
        }
        
        for(int i = 0; i < m ; i++){
            if(mp.find(A2[i]) != mp.end()){
                int counter = mp[A2[i]];
                while(counter--){
                    v.push_back(A2[i]);
                }
                mp.erase(A2[i]);
            }
        }
        
        for(auto x : mp){
            int counter = x.second;
            while(counter--){
                v.push_back(x.first);
            }
            mp.erase(x.first);
        }
        
        return v;
    } 
};
