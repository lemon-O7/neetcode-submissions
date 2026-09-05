class Solution {
public:
    vector<vector<int>> memo;
    int knapsack(int i,int cap,vector<int>& stones) {
        if(i<0 || cap==0) {
            return 0;
        }
        if(memo[i][cap]!=-1) return memo[i][cap];
        if(stones[i]<=cap){
            int no = knapsack(i-1,cap,stones);
            int yes = knapsack(i-1,cap-stones[i],stones)+stones[i];
            memo[i][cap] = no>yes ? no : yes;
            return memo[i][cap];
        }
        else {
            memo[i][cap] = knapsack(i-1,cap,stones);
            return memo[i][cap];
        }
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        
        int total=0;
        
        for(int i=0;i<n;i++) {
            total+=stones[i];
        }
        
        memo.assign(n, vector<int>((total/2)+1, -1));
        int g1 = knapsack(n-1,total/2,stones);
        int g2 = total - g1;

        return abs(g1-g2);
    }
};