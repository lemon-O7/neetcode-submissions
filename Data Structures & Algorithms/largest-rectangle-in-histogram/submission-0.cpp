class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        int n = heights.size();
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[i]<heights[st.top()]){
                int j = st.top();
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                ans = max(ans, heights[j] * width);
            }
            st.push(i);
        }
        while(!st.empty()) {
            int j = st.top();
            st.pop();
            int width = st.empty() ? n : n-st.top()-1;
            ans = max(ans, heights[j] * width);
        }
        
        return ans;
    }
};