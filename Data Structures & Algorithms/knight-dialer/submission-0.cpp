class Solution {
public:
    const int MOD = 1000000007;
    int knightDialer(int n) {
        vector<vector<int>> dp(n,vector<int>(10));
        vector<vector<int>> next = {
            {4,6}, {8,6}, {7,9}, {8,4}, {3,9,0}, {}, {7,1,0}, {2,6}, {1,3},{2,4}
        };
        for(int i=0;i<10;i++) dp[0][i] = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<10;j++) {
                for (int x : next[j]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][x]) % MOD;
                }
            }
        }
        int ans=0;
        for(int i=0;i<10;i++) ans=(ans+dp[n-1][i])%MOD;
        return ans;
    }
};