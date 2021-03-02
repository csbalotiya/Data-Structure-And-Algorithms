#include<bits/stdc++.h>
using namespace std;
/* Program of maximum sum of subarray which have unique Elements  */
int maximumUniqueSubarray(int arr[],int n){
    int res = 0, sum =0 , j = 0;
    map<int ,int> mp;       // use map for checking frequency
    for(int i = 0;i < n;i++){
        sum += arr[i];      //Increase sum by adding elements
        mp[arr[i]]++;
        while(j<i && mp[arr[i]] > 1){   // loop to check and remove repeated elements
            sum-= arr[j];
            mp[arr[j++]]--;   //mapping starts with index 1 
        }
        res = max(res,sum);   // save sum of subarray which we required 
    }
    return res;
}

int main() {
    /*int n = 7;
	int arr[] = {1,3,1,4,2,5,2};  */
	int n = 5;      // length of array
	int arr[] = {1,6,7,1,6};      // array use to store values

	cout<<maximumUniqueSubarray(arr,n); //calliing function and print 
	return 0;
}
