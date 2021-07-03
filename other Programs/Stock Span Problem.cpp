//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

/*
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
*/

class Solution{
    public:
 
    vector <int> calculateSpan(int arr[], int n){
       vector<int> ans  ;
       stack<pair<int,int>> s;
       
        for(int i = 0; i < n; i++){
            int day = 1;
            while(!s.empty() && s.top().first <= arr[i]){
                day += s.top().second;
                s.pop();
            }
            s.push({arr[i], day});
            ans.push_back(day);
        }
        return ans;
    }
};


