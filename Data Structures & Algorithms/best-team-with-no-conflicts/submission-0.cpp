class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(ages[i]>ages[j]) {
                    
                    int temp = ages[i];
                    ages[i] = ages[j];
                    ages[j] = temp;
                    temp = scores[i];
                    scores[i] = scores[j];
                    scores[j] = temp;
                }
                else if(ages[i]==ages[j]) {
                    if(scores[i]>scores[j]) {
                        int temp = ages[i];
                        ages[i] = ages[j];
                        ages[j] = temp;
                        temp = scores[i];
                        scores[i] = scores[j];
                        scores[j] = temp;
                    }
                }
            }
        }

        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++) {
            dp[i] = scores[i];
            for(int j=0;j<i;j++) {
                if(scores[j]<=scores[i]) {
                    dp[i] = max(dp[i],dp[j]+scores[i]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};