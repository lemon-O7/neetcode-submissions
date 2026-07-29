class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currsum = nums[0];
        int maxsum=currsum;
        int minsum=currsum;
        int mincurr = currsum;
        for(int i=1;i<nums.size();i++) {
            currsum = max(nums[i],currsum+nums[i]);
            mincurr = min(nums[i],mincurr+nums[i]);
            maxsum = max(maxsum,currsum);
            minsum = min(minsum,mincurr);
        }
        int total=nums[0];
        for(int i=1;i<nums.size();i++) {
            total += nums[i];
        }

        if(maxsum<0) return maxsum;

        return max(maxsum,total-minsum);
    }
};