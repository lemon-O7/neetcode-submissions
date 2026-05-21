class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int left=0,right=1;
        
        while(right<prices.size()) {
            
            if(prices[left]>prices[right]) {
                left=right;
            }
            
            profit = max(profit, prices[right] - prices[left]);
        
            right++;
        }
        return profit;
    }
};