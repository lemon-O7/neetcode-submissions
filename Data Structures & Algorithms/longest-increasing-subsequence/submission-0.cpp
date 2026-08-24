class Solution {
public:
    

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int x : nums) {
            int low = lower_bound(tails.begin(),tails.end(),x) -tails.begin();
            if(low == tails.size()) {
                tails.push_back(x);
            }
            else {
                tails[low] = x;
            }
        }
        return tails.size();
    }
};