class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size()-1;
        int n = board[0].size()-1;
        queue<pair<int,int>> cellswithO;
        for(int i=0;i<=m;i++) {
            if(board[i][0]=='O') {
                board[i][0]='S';
                cellswithO.push({i,0});
            }
            if(board[i][n]=='O') {
                board[i][n]='S';
                cellswithO.push({i,n});
            }
        }   
        for(int j=0;j<=n;j++) {
            if(board[0][j]=='O') {
                board[0][j]='S';
                cellswithO.push({0,j});
            }
            if(board[m][j]=='O') {
                board[m][j]='S';
                cellswithO.push({m,j});
            }
        }
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!cellswithO.empty()) {
            pair<int,int> cell = cellswithO.front();
            cellswithO.pop();

            for(auto& c : dir) {
                int ni = cell.first+c[0],nj =cell.second+c[1];
                if(ni>=0 && ni<=m && nj>=0 && nj<=n && board[ni][nj]=='O') {
                    cellswithO.push({ni,nj});
                    board[ni][nj]='S';

                } 
            }
        }

        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                if(board[i][j]=='S') {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
};