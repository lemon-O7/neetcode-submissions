class Solution {
public:
    vector<vector<int>> memo;
    int BFS(int i,int j,vector<vector<int>>& obstacleGrid) {
        int a,b;
        int m,n;
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        a=b=0;
        if(obstacleGrid[i][j]==1) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        if(i==m-1 && j==n-1) {
            return 1;
        }
        
        if(i+1<=m-1) {
            a= BFS(i+1,j,obstacleGrid); 
        }
        if(j+1<=n-1) {
            b=BFS(i,j+1,obstacleGrid);  
        }
        memo[i][j]=a+b;
        return memo[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memo.resize(m, vector<int>(n, -1));
        ans = BFS(0,0,obstacleGrid);
        return ans;
    }
};