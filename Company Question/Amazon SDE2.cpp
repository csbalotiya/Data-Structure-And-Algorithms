//https://leetcode.com/discuss/interview-experience/561225/amazon-sde-2-bangalore-india-march-2020

/*
 Question 1: People are standing in a row. Every person is assigned a number.
If the person left to you has a number lower than yours, you are eliminated.
Given the number of people and the numbers assigned to them.
You have to find the number of iterations after which no elimination will be done. (20 mins)

No of people - 5

3 2 6 4 5

3 2 4

3 2

Output - 2*/


int poisonousPlants(vector<int> p) {
    int minimum = p[0], maximum = INT_MAX;
    stack<pair<int, int>> stk;
    int ans = 0;
    for(int i=0; i<p.size(); i++) {
        int day = 1;
        while(!stk.empty() && p[i] <= p[stk.top().first]) {
            day = max(day, stk.top().second + 1);
            stk.pop();
        }
        if(stk.empty())
            day = -1;
        ans = max(ans, day);
        stk.push({i, day});
    }
    return ans<0?0:ans;
}
