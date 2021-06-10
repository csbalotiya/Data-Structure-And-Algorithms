//https://practice.geeksforgeeks.org/problems/relative-sorting4323/1#
// Example of map , map is always sorted according the key.

// C++ Solution :
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



// Python Solution :
class Solution:
 
    def relativeSort (self,A1, N, A2, M):
        frequency = {}
        for item in A1:
           if item in frequency:
              frequency[item] += 1
           else:
              frequency[item] = 1

        res = []
        for  i in A2:
            c = frequency[i]
            while(c!= 0):
                res.append(i)
                c -= 1
        
        A1.sort()
        for i in A1:
            if i not in A2:
                res.append(i)
                
        return res
        
