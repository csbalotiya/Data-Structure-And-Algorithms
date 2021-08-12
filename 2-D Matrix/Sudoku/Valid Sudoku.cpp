//https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int isValid(vector<vector<int>> mat){
        unordered_set<string> seen;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(mat[i][j] != 0){
                    
                    string temp1 = "row"+to_string(i) + to_string(mat[i][j]);            // for row
                    string temp2 = "col"+to_string(j) + to_string(mat[i][j]);            // for column
                    string temp3 = "box"+to_string((i/3)*3+j/3)+ to_string(mat[i][j]);   //for box
                    
                    if(seen.find(temp1) != seen.end())
                        return false;
                                        
                    if(seen.find(temp2) != seen.end())
                        return false;
                                        
                    if(seen.find(temp3) != seen.end())
                        return false;
                    
                    seen.insert(temp1);
                    seen.insert(temp2);
                    seen.insert(temp3);
                }   
            }
        }
        return true;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
