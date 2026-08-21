class Solution {
public:
    unordered_map<int,int> memo;
    int n;
    int DFS(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(amount<0) {
            return 1e9;
        }
        if(memo.contains(amount)) return memo[amount];
        int best = 1e9;
        for(int i=0;i<n;i++) {
            
            int result = DFS(coins,amount-coins[i]) +1;
            best = min(result,best);
        }
        memo[amount] = best;
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        int ans = DFS(coins,amount);
        if(ans == 1e9) {
            return -1;
        }
        else {
            return ans;
        }
    }
};