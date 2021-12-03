/*https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

*/

#include<bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int tillnow = arr[0];
    for (int i = 1;i < n; i++){ 
        arr[i] = max(arr[i], arr[i-1]+arr[i]);
        tillnow = max(tillnow, arr[i]);
    }
    return tillnow;
    
}

// { Driver Code Starts.

int main()
{
       
        cin>>n; //input size of array      
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
}

