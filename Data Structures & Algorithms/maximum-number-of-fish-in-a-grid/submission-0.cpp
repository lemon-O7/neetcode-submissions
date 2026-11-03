class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0 || vis[i][j]==true) {
            return 0;
        }
        vis[i][j] = true;

        return grid[i][j] + dfs(grid,vis,i-1,j) + dfs(grid,vis,i+1,j) + dfs(grid,vis,i,j-1) + dfs(grid,vis,i,j+1);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int fish=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                int curr=0;                
                if(grid[i][j]>0) {
                    curr=dfs(grid,vis,i,j);
                }
                fish = max(fish,curr);
            }
        }
        return fish;
    }
};