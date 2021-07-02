//https://leetcode.com/problems/find-k-closest-elements/

/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]*/



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        stable_sort(arr.begin(), arr.end(), [x](const auto a, const auto b){
            return abs(a - x) < abs(b - x);   // sort by distance from x
        });
        arr.resize(k);                        // choose first k elements
        sort(begin(arr), end(arr));           // sort the output in ascending order before returning
        return arr; 
    }
};
