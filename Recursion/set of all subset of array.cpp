/*
{1, 2, 3} -> the subsets will be {}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}. 
*/

#include<bits/stdc++.h>
using namespace std;

// Bit masking    O[n*2^n]
/*This method is very simple. It is based on bit-masking. The number of subsets of an array is 2N where N is the size
of the array. We basically generate N-bit binary string for all numbers in the range 0 to 2N – 1 and print array based on the string.
If the ith index of the binary string is 1, that means the ith index of the array is included in the subset.*/

void PrintAllSubsets(int *arr, int n){
    int ans =0 ;
    for(int snum = 0; snum < pow(2,n); snum++){
        for(int i=0;i<n;++i){
            if((snum&( 1<<i))!=0){
                cout<<arr[i]<<" ";
            }
        }cout<<endl;
    }
}

// backtracking Approch  O[2^n]
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index){
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {

        // include the A[i] in subset.
        subset.push_back(A[i]);

        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }

    return;
}

// below function returns the subsets of vector A.
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;

    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);

    return res;
}

int main(){
    int arr[] = {1,2,3}; // input array
    int n = 3;
    cout<<"Bit Masking : ";
    PrintAllSubsets(arr,n);
    cout<<"\n\n\nBy backtracking :";
    vector<int> array = { 1, 2, 3 };

    // res will store all subsets.
    // O(2 ^ (number of elements inside array))
    // because at every step we have two choices
    // either include or ignore.
    vector<vector<int> > res = subsets(array);

    // Print result
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
