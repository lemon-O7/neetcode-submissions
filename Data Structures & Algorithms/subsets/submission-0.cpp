class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void recur(vector<int>& nums,int i,vector<int>& cur) {
        if(i==nums.size()) {
            ans.push_back(cur);
            return;
        }
        recur(nums,i+1,cur);
        cur.push_back(nums[i]);     
        recur(nums,i+1,cur);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        recur(nums,0,cur);
        return ans;    
    }
};