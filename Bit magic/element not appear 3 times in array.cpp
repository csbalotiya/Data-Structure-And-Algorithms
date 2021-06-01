//https://leetcode.com/problems/single-number-ii/submissions/

// Find number which is not occure 3 times in an array
/*
Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/
#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& a, int k) {

        int n = a.size();

        int INT_SIZE = 8 * sizeof(unsigned int);
        int count[INT_SIZE];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < INT_SIZE; i++)
            for (int j = 0; j < n; j++)
                if ((a[j] & (1 << i)) != 0)
                    count[i] += 1;

        unsigned res = 0;
        for (int i = 0; i < INT_SIZE; i++)
            res += (count[i] % k) * (1 << i); // (1<<n) => 2 ** n

        return res;
    }

int main(){
   vector<int> nums = {0,1,0,1,0,1,99};
   cout<<singleNumber(nums,3);
    return 0;
}

