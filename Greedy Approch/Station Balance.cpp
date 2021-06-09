// https://algorithmist.com/wiki/UVa_410_-_Station_Balance
// take care of precision

#include <bits/stdc++.h>
using namespace std;

double solve(vector<int>& arr , int n, int chamber){

    int sum = 0;
    for(int x :arr)
        sum += x;

    double avg = double(sum) / double(chamber);
    //cout<<"sum "<<sum<<"\n";
    //cout<<"avg " << avg<<"\n";

    int temp =  chamber - (n % chamber);
    for(int i = 0; i < temp; i++){
        arr.push_back(0);
    }

    sort(arr.begin(), arr.end());

    double res = 0.00000;
    int size = arr.size();

    for(int i = 0; i < size/2; i++){
        res += double(abs(avg - double(arr[i] + arr[size-1-i])));
    }
    return res;
}

int main() {
    int t,n,chamber,tmp;
    cin>>t;
    while(t--){
        vector<int> arr;
        cin>>chamber>>n;
        for(int i =0; i < n; i++){
            cin>>tmp;
            arr.push_back(tmp);
        }
        printf("IMBALANCE = %.5lf\n\n", solve(arr, n ,chamber));
    }
    return 0;
}
