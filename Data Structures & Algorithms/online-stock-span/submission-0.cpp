class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 0;
        pair<int,int> pricespan = {price,1};
        while(!st.empty() && st.top().first<=price) {
            pricespan.second+= st.top().second;
            st.pop();
        }
        st.push(pricespan);
        return pricespan.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */