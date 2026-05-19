class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i,j;
        int n=nums.size();
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++){
                if(nums[i]==nums[j]) {
                    return true;
                }
            }
            
        }
        return false;
    }
};