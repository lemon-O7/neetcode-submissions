class Solution {
public:
    int n;
    unordered_map<int,int> map;
    int DFS(vector<int>& nums,int i) {
        if(i>=nums.size() || i<0) {
            map[i] = 0;
            return 0;
        }
        if(map.contains(i)) return map[i];
        map[i] = max(nums[i]+DFS(nums,i+2), DFS(nums,i+1));
        return map[i];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) {
            return nums[0];
        }
        vector<int> nums1,nums2;
        for(int i=0;i<n-1;i++) {
            nums1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++) {
            nums2.push_back(nums[i]);
        }
        int ans1=DFS(nums1,0);
        map.clear();
        int ans2=DFS(nums2,0);
        return max(ans1,ans2);
    }
};