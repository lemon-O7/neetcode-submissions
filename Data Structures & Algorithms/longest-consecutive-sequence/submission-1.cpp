class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;
        int result=0;
        for(int i=0;i<nums.size();i++) {
            numbers.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++) {
            int temp=1,x;
            x=nums[i];
            if(!numbers.count(nums[i]-1)) {
                while(numbers.count(x+1)) {
                    temp++;
                    x++;
                }
                if(temp>result) {
                    result=temp;
                }
            }
        }
        
        return result;
    }
};
