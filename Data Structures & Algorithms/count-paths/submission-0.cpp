class Solution {
public:
    vector<vector<int>> memo;
    int BFS(int i,int j,int m,int n) {
        int a,b;
        a=b=0;
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        if(i==m-1 && j==n-1) {
            return 1;
        }
        
        if(i+1<=m-1) {
            a= BFS(i+1,j,m,n); 
        }
        if(j+1<=n-1) {
            b=BFS(i,j+1,m,n);  
        }
        memo[i][j]=a+b;
        return memo[i][j];
    }

    int uniquePaths(int m, int n) {
        int ans;
        memo.resize(m, vector<int>(n, -1));
        ans = BFS(0,0,m,n);
        return ans;
    }
};