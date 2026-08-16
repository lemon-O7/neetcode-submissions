class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        for(int i=n-1;0<=i;i--) {
            if(i==n-1){
                dp[i]=cost[i];
            }
            else if(i==n-2) {
                dp[i]=cost[i];
            }
            else {
                dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
            }
        }
        return min(dp[0],dp[1]);
    }
};