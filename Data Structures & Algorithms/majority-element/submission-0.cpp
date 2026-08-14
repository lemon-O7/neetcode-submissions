class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++) {
            freq[nums[i]]++;
        }
        int max=INT_MIN;
        int ans;
        for(auto& [p,q] : freq) {
            if(q>max) {
                max = q;
                ans = p;
            }
        }
        return ans;
    }
};