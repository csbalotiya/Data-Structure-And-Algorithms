//https://leetcode.com/problems/remove-stones-to-minimize-the-total/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> heap;
        for(int x : piles)
            heap.push(x);
        
        for(int i = 0; i < k; i++){
            int temp = heap.top();
            heap.pop();
            temp -= floor(temp/2);
            heap.push(temp);
        }
        int ans = 0;
        while(!heap.empty()){
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};
