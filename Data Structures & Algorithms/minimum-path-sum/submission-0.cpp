class Solution {
public:
    vector<vector<int>> memo;
    int DFS(int i,int j,vector<vector<int>>& grid) {
        int down,right;
        int m,n;
        m=grid.size();
        n=grid[0].size();
        down=right=INT_MAX;
        
        if(i==m-1 && j==n-1) {
            return grid[i][j];
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        if(i+1<m) {
            down= DFS(i+1,j,grid); 
        }
        if(j+1<n) {
            right= DFS(i,j+1,grid);  
        }

        memo[i][j]=grid[i][j]+min(down,right);
        return memo[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        memo.resize(m, vector<int>(n, -1));
        
        return DFS(0,0,grid);
    }
};
