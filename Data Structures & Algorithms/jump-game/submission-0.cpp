class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canreach=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(i>canreach) {
                return false;
            }
            canreach = max(canreach,nums[i]+i);
           
        }
        if(canreach >= nums.size()-1) {
            return true;
        }
        return false;
    }
};