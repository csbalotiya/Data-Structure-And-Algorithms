//Find K Closest Elements
//https://leetcode.com/problems/find-k-closest-elements/

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
