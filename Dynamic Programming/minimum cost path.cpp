/*https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1#
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
*/
class Solution{
  public :
bool isValid(int i, int j, int n, int m){
        if(i >= 0 && j >= 0 && i < n && j < m)
            return true;
        else
            return false;
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[0][0] = grid[0][0];
       
        vector<vector< int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        priority_queue< pair<int, pair<int,int>>,
                        vector<pair<int, pair<int,int>>>,
                        greater<pair<int, pair<int,int>>>   >pq; // Min Heap
            
        pq.push({grid[0][0], {0,0}});
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            for(int k = 0; k < 4; k++){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(isValid(x,y,n,m) && (dp[i][j] + grid[x][y] < dp[x][y])){
                    dp[x][y] = dp[i][j] + grid[x][y];
                    pq.push({dp[x][y], {x,y}});
                }
            }
        }
       /* for(int i = 0; i < n; i++){
            for(int j = 0; j <m; j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }*/
        return dp[n-1][m-1];
    }
};
