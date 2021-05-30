//https://leetcode.com/problems/diagonal-traverse/

/*Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();
    map<int , vector<int>> mp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mp[i+j].push_back(mat[i][j]);
        }
    }

    vector<int> res;
    int level = 0;
    for(auto& [k,v] : mp){
        if(level % 2 == 1){
            copy(v.begin(),v.end(), back_inserter(res));
        }else{
            copy(v.rbegin(),v.rend(), back_inserter(res));
        }
        level+=1;
    }
    return res;

}

int main(){
    vector<vector<int>> mat= {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans = findDiagonalOrder(mat);

    for(auto X : ans){
        cout<<X<<" ";
    }
	return 0;
}



