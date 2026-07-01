class Solution {
public:
    void BFS(vector<vector<int>>& heights,queue<pair<int,int>>& q, vector<vector<bool>>& visited) {

        while(!q.empty()) {
            pair<int,int> cell = q.front();
            q.pop();
            if(cell.first+1<heights.size()) {
                if(visited[cell.first+1][cell.second]==false) {
                    if(heights[cell.first+1][cell.second]>= heights[cell.first][cell.second]) {
                        q.push({cell.first+1,cell.second});
                        visited[cell.first+1][cell.second]=true;
                    }
                }
            }
            if(cell.second+1<heights[0].size()){
                if(visited[cell.first][cell.second+1]==false) {
                    if(heights[cell.first][cell.second+1]>= heights[cell.first][cell.second]) {
                        q.push({cell.first,cell.second+1});
                        visited[cell.first][cell.second+1]=true;
                    }
                }
            }
            if(cell.first-1>=0){
                if(visited[cell.first-1][cell.second]==false) {
                    if(heights[cell.first-1][cell.second]>= heights[cell.first][cell.second]) {
                        q.push({cell.first-1,cell.second});
                        visited[cell.first-1][cell.second]=true;
                    }
                }
            }
            if(cell.second-1>=0){
                if(visited[cell.first][cell.second-1]==false) {
                    if(heights[cell.first][cell.second-1]>= heights[cell.first][cell.second]) {
                        q.push({cell.first,cell.second-1});
                        visited[cell.first][cell.second-1]=true;
                    }
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;
        vector<vector<int>> ans;
        int m = heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            pacific.push({i, 0});         
            pac[i][0]=true; 
            atlantic.push({i, n - 1});
            atl[i][n-1]=true;      
        }
        for(int j=0;j<n;j++) {
            pacific.push({0,j});
            pac[0][j]=true;
            atlantic.push({m-1,j});
            atl[m-1][j]=true;
        }

        BFS(heights,pacific,pac);
        BFS(heights,atlantic,atl);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pac[i][j]==true && atl[i][j]==true) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};