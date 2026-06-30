class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int count =0;
        int time=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==2) {
                    rotten.push({i,j});
                }
                if(grid[i][j]==1) {
                    count++;
                }
            }
        }
        while(!rotten.empty()) {
            int levelSize = rotten.size();
            bool rottedThisLevel = false;
            for(int k = 0; k < levelSize; k++) {
                pair<int,int> cell = rotten.front();
                rotten.pop();
                int i=cell.first;
                int j=cell.second;
                
                if(i+1<grid.size() && grid[i+1][j]==1) {
                    count--;
                    rottedThisLevel = true;
                    grid[i+1][j]=2;
                    rotten.push({i+1,j});
                }
                if(i-1>=0 && grid[i-1][j]==1) {
                    count--;
                    rottedThisLevel = true;
                    grid[i-1][j]=2;
                    rotten.push({i-1,j});
                }
                if(j+1<grid[i].size() && grid[i][j+1]==1) {
                    count--;
                    rottedThisLevel = true;
                    grid[i][j+1]=2;
                    rotten.push({i,j+1});
                }
                if(j-1>=0 && grid[i][j-1]==1) {
                    count--;
                    rottedThisLevel = true;
                    grid[i][j-1]=2;
                    rotten.push({i,j-1});
                }
            }
            if(rottedThisLevel) time++;
        }
        if(count>0) {
            return -1;
        }

        return time;
    }
};