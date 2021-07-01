//https://leetcode.com/problems/gray-code/

/*Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]*/


class Solution {
public:
    vector<int> grayCode(int n) {
        
        ios::sync_with_stdio(false),cin.tie(0);
        vector<int> ans = {0};
        for(int i = 0; i < n; i++){
            int temp = pow(2,i);
            for(int j = ans.size()-1; j >= 0; j--){
                ans.push_back(ans[j] + temp);
            }
        }
        return ans;
    }
};

/*  Python Solution is Also here
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0]
        for i in range(0, n):
            temp = 2**(i)
            for j in ans[::-1]:
                ans.append(j + temp)
        return ans
        */
