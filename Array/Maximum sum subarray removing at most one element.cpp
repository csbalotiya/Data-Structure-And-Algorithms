// C++ program to get maximum sum subarray removing at-most one element
#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int n){
	for(int i = 0; i<n; i++)    cout<<arr[i]<<" ";  cout<<"\n";
}

int maxSumSubarrayRemovingOneEle(int arr[], int n){

	int fw[n], bw[n];
	int cur_max = arr[0], max_so_far = fw[0] = arr[0];
	for (int i = 1; i < n; i++)	{
		cur_max = max(arr[i], cur_max + arr[i]);
		max_so_far = max(max_so_far, cur_max);
		fw[i] = cur_max;
	}

	cur_max = max_so_far = bw[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; i--){
		cur_max = max(arr[i], cur_max + arr[i]);
		max_so_far = max(max_so_far, cur_max);
		bw[i] = cur_max;
	}

	int fans = max_so_far;
	for (int i = 1; i < n - 1; i++)
		fans = max(fans,max(0, fw[i - 1]) +max(0, bw[i + 1]));
		if(fans==0){
			return *max_element(arr,arr+n);
		}
    print(fw,n);
    print(arr,n);
    print(bw,n);
	return fans;
}


int main(){
	int arr[] = {1,2,3,-4,-5,-6,1,-2,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSumSubarrayRemovingOneEle(arr, n);
	return 0;
}

