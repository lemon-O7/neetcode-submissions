class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i,j;
        i=0;
        j=0;
        while(j<nums.size()) {
            if(nums[j]%2==0) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
            j++;
        }
        return nums;
    }
};