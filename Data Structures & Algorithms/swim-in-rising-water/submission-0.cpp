class Solution {
public:
    int n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool reach(vector<vector<int>>& grid, int T){
        if(grid[0][0]>T) return false;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            if(x==n-1 && y==n-1) return true;
            for(int d=0;d<4;d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(vis[nx][ny] || grid[nx][ny] > T) continue;
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                m = max(m,grid[i][j]);
            }
        }
        int l,mid;
        l=0;
        while(l<m) {
            mid = l+(m-l)/2;
            if(reach(grid,mid)){
                m=mid;
            }
            else {
                l=mid+1;
            }
        }
        return l;
    }
};