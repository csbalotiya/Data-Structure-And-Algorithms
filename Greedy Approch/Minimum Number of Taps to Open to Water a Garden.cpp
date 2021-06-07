//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int mine = 0;
        int maxe = 0;
        int open  = 0;
        
        while(maxe < n){
            for(int i = 0; i < ranges.size(); i++){
                if(i-ranges[i] <= mine && i+ranges[i] > maxe)
                    maxe = i + ranges[i];
            }
            if(mine == maxe) return -1;
            open++;
            mine = maxe;
        }
        return open;
    }
};
