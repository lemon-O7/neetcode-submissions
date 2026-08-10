class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        unordered_map<int,int> freq;
        for(int j=0;j<nums.size();j++) {
            if(freq[nums[j]]>=1) return true;
            freq[nums[j]]++;
            if(j-i>=k) {
                freq[nums[i]]--;
                i++;
            }
        }

        return false;
    }
};