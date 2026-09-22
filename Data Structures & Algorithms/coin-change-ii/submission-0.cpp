class Solution {
public:
    vector<vector<int>> memo;
    int ways(int cap,vector<int>& coins,int i) {
        if(cap<0 || i<0) {
            return 0;
        }
        if(cap==0) {
            return 1;
        }
        if(memo[cap][i]!=-1) return memo[cap][i];

        int a = ways(cap-coins[i],coins,i);
        int b=0;

        if(i>0) {
            b=ways(cap,coins,i-1);
        }
        memo[cap][i] = a+b;
        return memo[cap][i];
    }
    int change(int amount, vector<int>& coins) {
        memo.assign(amount+1,vector<int>(coins.size(),-1));
        return ways(amount,coins,coins.size()-1);
    }
};