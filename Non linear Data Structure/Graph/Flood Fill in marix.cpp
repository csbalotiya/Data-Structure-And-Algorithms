//https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     
        int n = image.size(), m = image[0].size();
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int, int>>q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int curr = image[sr][sc];
        while(!q.empty()){
            pair<int, int>p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();
            visited[r][c] = 1;
        
            if(r-1 >= 0 && image[r-1][c] == curr && !visited[r-1][c]){
                q.push({r-1, c});
            }
            if(r+1 < n && image[r+1][c] == curr && !visited[r+1][c]){
                q.push({r+1, c});
            }
            
            if(c-1 >= 0 && image[r][c-1] == curr && !visited[r][c-1]) {
                q.push({r, c-1});
            }
            if(c+1 < m && image[r][c+1] == curr && !visited[r][c+1]){
                q.push({r, c+1});    
            }
            image[r][c] = newColor;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout<<image[i][j]<<" ";
            }cout<<"\n";
        }
        return image;        
    }
};
