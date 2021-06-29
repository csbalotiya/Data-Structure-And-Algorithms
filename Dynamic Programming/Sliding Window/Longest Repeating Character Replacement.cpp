//https://leetcode.com/problems/longest-repeating-character-replacement/
/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> count(26,0);
        int left = 0;
        int maxchar = INT_MIN, maxval = 0;
        
        for(int right = 0; right < s.size(); right++){
           
            int windowsize = right-left+1;
            count[s[right]-'A']++;
            maxchar = max(maxchar, count[s[right]-'A']);
            int replace = windowsize - maxchar;
            if(replace > k){
                count[s[left]-'A']--;
                left++;
            }else{
                maxval = max(maxval, windowsize);
            }
        }
        return maxval;
    }
};

