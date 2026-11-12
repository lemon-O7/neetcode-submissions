class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> freq(strs.size(),{0,0});
        int k=strs.size();
        for(int i=0;i<k;i++) {
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0')freq[i].first++;
                if(strs[i][j]=='1')freq[i].second++;
            }
        }
        int x=0;
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=1;i<=k;i++) {
            int y= freq[i-1].first,z=freq[i-1].second;
            for(int a=0;a<=m;a++) {
                for(int b=0;b<=n;b++) {
                    dp[i][a][b] = dp[i-1][a][b];
                    if(y<=a && z<=b) {
                        dp[i][a][b] = max(dp[i][a][b],1+dp[i-1][a-y][b-z]);
                    }
                }
            }
        }
        return dp[k][m][n];
    }
};