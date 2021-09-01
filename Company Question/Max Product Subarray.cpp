//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(),mx = 1, mn = 1, tillnow = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
                swap(mn, mx);
            mn = min(nums[i]*mn, nums[i]);
            mx = max(nums[i]*mx, nums[i]);
            tillnow = max(tillnow, mx);
        }
        return tillnow;
    }
};

/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int m = INT_MIN;
    
    int p=1;
    
    for(int num : nums){
        p *= num;
        m=max(p,m);
        if(p == 0)p = 1;
        
    }
    
    p = 1;
    for(int i=nums.size()-1;i>=0;i--){
        p *= nums[i];
        m=max(p,m);
        if(p ==0) p = 1;
    }
    
    return m;
}
};
*/
