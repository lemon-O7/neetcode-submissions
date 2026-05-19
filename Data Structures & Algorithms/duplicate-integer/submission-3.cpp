class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dupli;
        for(int i=0;i<nums.size();i++) {
            dupli.insert(nums[i]);
        }
        if(dupli.size()==nums.size()) {
            return false;
        }
        else {
            return true;
        }
    }
};