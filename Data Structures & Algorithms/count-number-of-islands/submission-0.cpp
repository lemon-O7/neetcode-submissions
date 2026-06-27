class Solution {
public:
    
    void DFS(vector<vector<char>>& grid,int i,int j){
        if(grid[i][j]=='1') {
            grid[i][j]='0';
            if(i+1<grid.size()) {
                DFS(grid,i+1,j);}
            if(i-1>=0) {
                DFS(grid,i-1,j);}
            if(j+1<grid[i].size()) {    
                DFS(grid,i,j+1);}
            if(j-1>=0) {
                DFS(grid,i,j-1);}
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    islands++;
                    DFS(grid,i,j);}
            }
        }
        
        return islands;
    }
};