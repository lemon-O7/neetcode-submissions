class Solution {
public:
    int total=0;
    void recur(vector<int>& nums,int i,int cur) {
        if(i==nums.size()) {
            total+=cur;
            return ;
        }
        recur(nums,i+1,cur^nums[i]);
        recur(nums,i+1,cur);
    }
    int subsetXORSum(vector<int>& nums) {
        recur(nums,0,nums[0]);
        return total;
    }
};