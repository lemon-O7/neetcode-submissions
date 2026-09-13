class Solution {
public:
    vector<int> memo;
    int numSquares(int n) {
        if(memo.empty()) memo.assign(n+1,-1);
        if(memo[n]!=-1) return memo[n];
        int i,ans;
        ans = n;
        if(n==0) return 0;
        for(i=1;i*i<=n;i++) {
            memo[n] = min(ans,1+numSquares(n-(i*i)));
            ans = memo[n];
        }
        return memo[n];
    }
};