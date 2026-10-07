class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++) {
            int j = 0;
            while(nums2[j]!=nums1[i] && j<nums2.size()) j++;
            j++;
            bool flag=0;
            for(;j<nums2.size();j++) {
                if(nums2[j]>nums1[i]) {
                    flag=true;
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(flag!=1) ans.push_back(-1);
             
        }
        return ans;
    }
};