class Solution {
public:
    void sortColors(vector<int>& nums) {
       int r,w,b;
       r=w=b=0;
       for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) r++;
            if(nums[i]==1) w++;
            if(nums[i]==2) b++;
       } 
       int i=0;
        for(;i<r;i++) {
            nums[i] = 0;
        }
        for(;i<r+w;i++) nums[i] = 1;
        for(;i<r+w+b;i++) nums[i] = 2;
    }
};
