//Amazon  Goldman Sachs   Microsoft
//https://www.interviewbit.com/old/problems/largest-number/

bool compare(int a, int b){
        string num1 = to_string(a) + to_string(b);
        string num2 = to_string(b) + to_string(a);
        return num1 > num2;
    }

string Solution::largestNumber(const vector<int> &arr) {

        string res = "";
        vector<int> nums(arr);
        sort(nums.begin(), nums.end(),compare);
        if(nums[0] == 0)
            return "0";
        for(int x: nums)
            res += to_string(x);
        
        return res;
}

