//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

//sort array in 111... 00.... 2.... order , array consist of only 0,1,2;

#include <bits/stdc++.h>
using namespace std;

void sort102(int arr[], int n){
    int lo = 0, hi = n-1,mid = 0;
    while(mid<= hi){
        int x = arr[mid];
        switch(x){
            
            case 0:
                mid++;
                break;
            
            case 1:
                swap(arr[lo++], arr[mid++]);
                break;
            
            case 2:
                swap(arr[mid],arr[hi--]);
                break;
        }
    }

}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

int main(){
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
    
	cout << "array Before segregation ";
	printArray(arr, n);

	sort102(arr, n);
	cout << "\n\narray after segregation ";
	printArray(arr, n);

	return 0;
}
