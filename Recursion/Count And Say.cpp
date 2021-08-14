//https://www.interviewbit.com/problems/count-and-say/
//https://leetcode.com/problems/count-and-say/
//https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1#


class Solution {
public:   
    string countAndSay(int p) {
        
        if(p == 1)  return "1";
        
        string curr = "";
        string prev = countAndSay(p-1);
        int c = 0;
        
        for(int i = 0; i < prev.size(); i++){
            c += 1;
            if(i == prev.size()-1 || prev[i] != prev[i+1]){
                curr += to_string(c);
                curr += prev[i];
                c = 0;
            }
        }
        return curr;
    }
};
