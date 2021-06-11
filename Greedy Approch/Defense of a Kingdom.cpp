//https://www.spoj.com/problems/DEFKIN/

#include<bits/stdc++.h>
using namespace std;

int fun(vector<pair<int, int> > arr){

/*    for(auto& p : arr)
        cout<<p.first <<" " << p.second<<"\n";  */

    int x = 0, y = 0;
    for(int i = 1; i < arr.size(); i++){
        x = max(x, abs(arr[i-1].first - arr[i].first) - 1);
        y = max(y, abs(arr[i-1].second - arr[i].second) - 1);
    }
    return x*y;  // max Safe Area
}
int main(){

    int length , width ;
    int numOfPosition ;
    cin>> length >> width >> numOfPosition ;
    vector< pair< int, int> > arr;

    arr.push_back( {0, 0} );  // starting inedx
    int x,y;
    while(numOfPosition--){
        cin>>x>>y;
        arr.push_back({x, y});
    }
    arr.push_back({length, width});  // last index

    cout << fun(arr);
    return 0;
}

/*
Input:
15 8 3
3 8
11 2
8 6

Output:
12
*/
