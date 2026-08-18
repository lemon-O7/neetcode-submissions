class Solution {
public:
    unordered_map<int,int> map;
    int dfs(vector<int>& nums,int i) {
        if(i>=nums.size() || i<0) {
            map[i]=0;
            return 0;
        }
        if(map.contains(i)) {
            return map[i];
        }
        map[i] = max(nums[i]+dfs(nums,i+2),dfs(nums,i+1));
        return map[i]; 
    }
    int rob(vector<int>& nums) {
        
        return dfs(nums,0);
    }
};