class Solution {
public:
    int jump(vector<int>& nums) {
        int winend,farthest,jumps;
        jumps =0;
        winend =0;
        farthest =nums[0];
        for(int i=0;i<nums.size()-1;i++) {
            farthest = max(farthest,nums[i]+i);
            if(i==winend) {
                winend = farthest;
                jumps++;
            }
            
        }
        return jumps;
    }
};