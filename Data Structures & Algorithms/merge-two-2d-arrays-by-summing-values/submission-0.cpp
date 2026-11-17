class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i,j;
        i=j=0;
        vector<vector<int>> nums;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i][0]==nums2[j][0]) {
                nums.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]) {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        for(;i<nums1.size();i++) nums.push_back(nums1[i]);
        for(;j<nums2.size();j++) nums.push_back(nums2[j]);
        return nums;
    }
};