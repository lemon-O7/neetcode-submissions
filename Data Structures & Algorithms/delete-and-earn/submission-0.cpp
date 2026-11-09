class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int vmax=INT_MIN;
        
        for(int i=0;i<n;i++) {
            if(vmax<nums[i]) {
                vmax=nums[i];
            }
        }
        vector<int> points(vmax+1,0);
        for(int i=0;i<n;i++) {
            points[nums[i]] +=nums[i];
        }
        vector<int> dp(vmax+1,0);
        dp[0]=0;
        dp[1]=points[1];
        for(int i=2;i<=vmax;i++) {
            dp[i] = max(dp[i-1],dp[i-2]+points[i]);
        }
        return dp[vmax];
    }
};