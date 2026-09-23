class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>total || (total+target)%2 != 0) return 0;

        int pos = (total+target)/2;
        vector<int> dp(pos+1,0); 

        dp[0]= 1;
        for(int num : nums) {
            for(int cap = pos;cap>=num;cap--) {
                dp[cap] += dp[cap-num]; 
            }
        }

        return dp[pos];
    }
};
