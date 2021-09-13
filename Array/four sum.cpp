// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int> > res;
        sort(arr.begin(), arr.end());
        map<vector<int> , int> mp;
        for(int i = 0; i < n-3; i++){
            if (i > 0 && arr[i - 1] == arr[i])  continue;
            for(int j = i+1; j < n-2; j++){
                if (j > i + 1 && arr[j] == arr[j - 1])  continue;
                int t = k - arr[i]-arr[j];
                int l = j+1, r = n-1;
                while(l < r){
                    if(arr[l] + arr[r] == t){
                        vector<int> cur {arr[i], arr[j], arr[l], arr[r]};
                        if(mp[cur] == 0) {
                          res.push_back(cur);
                          mp[cur] = 1;
                        }
                        l+=1;
                        r-=1;
                    }else if(arr[l] + arr[r] < t){
                        l+=1;
                    }else{
                        r-=1;
                    }
                }
            }
        }
        return res;
    }
};
