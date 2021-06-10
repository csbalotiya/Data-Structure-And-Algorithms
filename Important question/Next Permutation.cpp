//https://leetcode.com/problems/next-permutation/
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int idx = -1;
        
        int i=1;
        int lastInc = -1;
        while(i<n) {    //Find the peak of last ASC order
            if(nums[i]>nums[i-1])
                idx = i;
            i+=1;
        }
        
        if(idx == -1){ // array is sorted in descending order
            for(int i = 0; i < n/2; i++){
                swap(nums[i], nums[n-i-1]);
            }
            return ;
        }
        
        int peek = nums[idx];
        int lastidx = idx;
        
        for(int i = idx; i < n; i++){
            if(nums[i] < nums[lastidx] && nums[i] > nums[idx-1]){
                lastidx = i;
            }
        }
        swap(nums[lastidx], nums[idx-1]);
        sort(nums.begin()+idx, nums.end());
        
    }
};
