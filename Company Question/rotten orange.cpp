#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &arr,int n, int m, int i, int j){
    if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
int timer(vector<vector<int>> &arr, int n, int m){

    bool change = false;
    int day = 0;
    int no = 2;
    while(true){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(arr[i][j] == no) // 2=> rotten
                {
                    if(isValid(arr,n,m,i+1,j) && arr[i+1][j] == 1){
                        arr[i+1][j] = arr[i][j]+1;
                        change = true;
                    }
                    if(isValid(arr,n,m,i-1,j) && arr[i-1][j] == 1){
                        arr[i-1][j] = arr[i][j]+1;
                        change = true;
                    }
                    if(isValid(arr,n,m,i,j+1) && arr[i][j+1] == 1){
                        arr[i][j+1] = arr[i][j]+1;
                        change = true;
                    }
                    if(isValid(arr,n,m,i,j-1) && arr[i][j-1] == 1){
                        arr[i][j-1] = arr[i][j]+1;
                        change = true;
                    }
                }
            }
        }
        if(!change)
            break;
        change = false;
        day++;
        no++;
    }
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// if any orange is found to be not rotten then ans is not possible
			if (arr[i][j] == 1)
				return -1;
		}
	}
    return no-2;
}
int main(){

    vector<vector<int>> arr = {{2,1,0,2,1},
                               {1,0,1,2,1},
                               {1,0,0,2,1}};

    int n = arr.size();
    int m = arr[0].size();

    cout<<timer(arr,n,m);

}
