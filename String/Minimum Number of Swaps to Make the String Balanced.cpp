//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
/*
Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
*/

class Solution {
public:
    int minSwaps(string s) {
        int curr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[')
                curr++;
            else if(curr > 0)
                curr--;
        }
        return (curr+1)/2;
    }
};
