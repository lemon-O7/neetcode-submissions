class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> columns(9);
        vector<set<char>> boxs(9);

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') continue;

                int boxindex = (i/3)*3+(j/3);
                if(rows[i].count(board[i][j]) || columns[j].count(board[i][j]) || boxs[boxindex].count(board[i][j])) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                boxs[boxindex].insert(board[i][j]);
            }
        }
        
        
        
        return true;
    }
};
