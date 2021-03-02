#include<bits/stdc++.h>
using namespace std;
/* Program of Largest subarray with 0 sum  */
int maxLen(int arr[], int n){
    map<int, int> presum;

    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result

    for (int i = 0; i < n; i++) {
        sum += arr[i];      // Add current element to sum
        if (sum == 0)
            max_len = i + 1;

        if (presum.count(sum)) {    // Look for this sum in Hash table
            max_len = max(max_len, i - presum[sum]);  // If this sum is seen before, then update max_len
        }else {
            presum[sum] = i;    // Else insert this sum with index in hash table
        }
    }
    return max_len;
}

int main() {
	int n = 8;   // length of array
	int arr[] = {15,-2,2,-8,1,7,10,23};  // array use to store values

	cout<<maxLen(arr,n);
	return 0;
}
