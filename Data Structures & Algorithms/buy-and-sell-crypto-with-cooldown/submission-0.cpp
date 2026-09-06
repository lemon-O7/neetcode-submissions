class Solution {
public:
    vector<vector<int>> memo;
    int Search(int i,bool holding,vector<int>& prices) {
        if(i>=prices.size()) return 0;
        if(memo[i][holding] != -1) {
            return memo[i][holding];
        }
        if(holding == true) {
            memo[i][holding] = max(prices[i]+Search(i+2,false,prices),Search(i+1,true,prices));
            return memo[i][holding];
        }
        else {
            memo[i][holding] = max(-prices[i]+Search(i+1,true,prices),Search(i+1,false,prices));
            return memo[i][holding];
        }
    }

    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size(),vector<int>(2, -1));
        return Search(0,false,prices);
    }
};