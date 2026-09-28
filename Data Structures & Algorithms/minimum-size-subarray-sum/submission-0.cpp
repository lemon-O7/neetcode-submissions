class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left,right,sum;
        left = right = sum =0;
        int ans = INT_MAX;
        for(;right<nums.size();right++) {
            sum += nums[right];
            while(sum >= target) {
                ans = min(ans,right-left+1);
                sum -= nums[left++];
            }
        }
        return ans!=INT_MAX ? ans : 0;
    }
};