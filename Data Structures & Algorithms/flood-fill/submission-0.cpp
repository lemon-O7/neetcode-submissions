class Solution {
public:
    bool isValid(vector<vector<bool>>& vis,int row,int col) {
        if(row<0 || col<0 || row >= vis.size() || col >= vis[0].size()) return false;
        if(vis[row][col]) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dRow[] = { -1, 0, 1, 0 };
        int dCol[] = { 0, 1, 0, -1 };
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int bef = image[sr][sc];
        while(!q.empty()) {
            pair<int,int> cell = q.front();
            q.pop();
            image[cell.first][cell.second] = color;
            for(int i=0;i<4;i++) {
                int adjx = cell.first+dRow[i];
                int adjy = cell.second+dCol[i];
                if(isValid(vis,adjx,adjy) && image[adjx][adjy] == bef) {
                    q.push({adjx,adjy});
                    vis[adjx][adjy] = true;
                }
            }
        }
        return image;
    }
    
};