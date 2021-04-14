
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr) {
        int ans = 0,profit = 0 ,pur =100000;
        for(int i = 0;  i < arr.size() ;i++){
            pur = min(arr[i] , pur);
            profit = max(profit , arr[i]- pur);
        }
        return profit;
    }

int main(){

    vector<int> v ;
    v = {7,1,5,3,6,4};
    cout<<maxProfit(v);
return 0;
}
