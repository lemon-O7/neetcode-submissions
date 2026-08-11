class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int n) {
        if(n == 0) {
            return 1;
        }
        if(n<0) {
            return 0;
        }
        if(memo.count(n)) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};