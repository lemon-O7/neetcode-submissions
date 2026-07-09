class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result;
        int sum;
        result=sum=nums[0];
        for(int i=1;i<nums.size();i++) {
            sum = max(nums[i],sum+nums[i]);
            result = max(sum,result);
        }
        return result;
    }
};