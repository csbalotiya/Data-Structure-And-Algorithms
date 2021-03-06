/*
Quick sort is based on divide-and-conquer. 
The average time complexity of this algorithm is O(n*log(n)) but
the worst case complexity is O(n^2). {The worst case happens when array is already sorted either in ascending or descending order.}
To reduce the chances of the worst case here Quicksort is implemented using randomization.
*/

#include<iostream>
using namespace std;
int partition (int arr[], int low, int high){
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	for (int j = low; j <= high- 1; j++){  // If current element is smaller than or  equal to pivot
		if (arr[j] <= pivot){
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high){
	if (low < high){				// n element * divide and conquer take log(n) = nlog(n)
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size){
	for (int i=0; i < size; i++)
		cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	cout<<"Sorted array:  \n";
	printArray(arr, n);
	return 0;
}
