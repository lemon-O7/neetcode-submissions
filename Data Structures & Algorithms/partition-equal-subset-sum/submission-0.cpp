class Solution {
public:
    vector<vector<int>> memo;

    int knapsack(vector<int>& nums,int i,int temp) {
        if(i==0 || temp==0) {
            memo[i][temp] =0;
            return 0;
        }
        if(memo[i][temp]!=-1) return memo[i][temp];
        if(nums[i]<=temp){
            int no = knapsack(nums,i-1,temp);
            int yes = knapsack(nums,i-1,temp-nums[i])+nums[i];
            memo[i][temp] = no>yes ? no : yes;
            return memo[i][temp];
        }
        else {
            memo[i][temp] = knapsack(nums,i-1,temp);
            return memo[i][temp];
        }
        
    }

    bool canPartition(vector<int>& nums) {
        int target=0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            target+=nums[i];
        }
        if(target%2 != 0) return false;
        target = target/2;
        
        memo.assign(n, vector<int>(target + 1, -1));
        if(target == knapsack(nums,nums.size()-1,target)) return true;

        return false;
    }
};