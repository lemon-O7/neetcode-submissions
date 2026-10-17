class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> prev(nums.size(),-1);
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }
            }
        }
        int ind=0;
        for(int i=0;i<nums.size();i++) {
            if(dp[i]>dp[ind]) ind = i;
        }
        vector<int> ans;
        while(ind != -1) {
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }
        return ans;
    }
};