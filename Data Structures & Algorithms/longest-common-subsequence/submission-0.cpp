class Solution {
public:
    vector<vector<int>> memo;
    int DFS(int i,int j,string& text1, string& text2) {
        if(i<0 || j<0) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        if(text1[i]==text2[j]) {
            memo[i][j] = 1+DFS(i-1,j-1,text1,text2);
            
        }
        else {
            memo[i][j] = max(DFS(i-1, j, text1, text2), DFS(i, j-1, text1, text2));
        }
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        memo.assign(m, vector<int>(n, -1));
        
        return DFS(m-1,n-1,text1,text2);
    }
};
