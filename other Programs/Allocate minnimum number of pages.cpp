#include<bits/stdc++.h>
using namespace std;
   int findPages(int arr[], int n, int m) {
    int sum = 0, mx = INT_MIN;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        mx=max(mx,arr[i]);  //find max for starting range
    }
    if(m > n) { //return -1 if students are greater than number of bundel of pages
        return -1;
    }
    int f=mx, l=sum;
    int ans = INT_MAX;
    while(f <= l) { // use binary search
        int mid = (f+l)/2;   //set mid
        int cnt = 1, t1 = 0;
        for(int i=0;i<n;i++) {
            if(arr[i]>mid){  // element greater than assumed point the break
                cnt = m+1;
                break;
            }
            if (t1 + arr[i] > mid) {  // check allocate more pages to student if less than assumed point
                cnt++;                  // increment student
                t1 = arr[i];
                if (cnt > m)            //break if student greater than given
                    break;
            }
            else
                t1 += arr[i];   //allocate more pages to student if less than assumed point

        }

        if(cnt > m) {   // increase range set starting point
            f = mid+1;
        }
        else {
            l = mid-1;  //set lower point
            ans = mid;
        }


    }
    return ans;

}
int main() {
    int n= 4;
    int arr[] = {12, 34, 67, 90};
    int student = 2;
    cout<<"Minimum allocated pages are : "<<findPages(arr,n,student);
    return 0;

}
