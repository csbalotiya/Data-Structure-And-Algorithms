//https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1#

// Expected Time Complexity : O(NlogN)
//Expected Auxilliary Space : O(N)
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
                mp[nums[i]] += 1;
        }
        vector<int> res;
        priority_queue<pair<int, int>>pq;
        for(auto &x : mp){
            pq.push({ x.second, x.first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
