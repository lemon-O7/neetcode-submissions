class Solution {
public:
    vector<vector<int>> memo;
    int score(vector<int>& piles,int i,int j) {
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = max(piles[i]-score(piles,i+1,j),piles[j]-score(piles,i,j-1));
        return memo[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        memo.assign(piles.size(),vector<int>(piles.size(),-1));
        int a = score(piles,0,piles.size()-1);

        return a>0;
    }
};