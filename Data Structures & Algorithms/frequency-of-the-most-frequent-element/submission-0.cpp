class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l,r;
        l=r=0;
        long long sumofwindow=0;
        for(;r<n;r++) {
            sumofwindow+=nums[r];
            if(k<((long long)nums[r]*(r-l+1))-sumofwindow) {
                sumofwindow-=nums[l];
                l++;
            }
        }
        return r-l;
    }
};