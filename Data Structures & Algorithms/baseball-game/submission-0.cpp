class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++) {
            if(operations[i]=="+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
                continue;
            }
            else if(operations[i]=="C") {
                st.pop();
                continue;
            }
            else if(operations[i]=="D") {
                st.push(2*st.top());
                continue;
            }
            else {
                st.push(stoi(operations[i]));
            }  

        }
        int ans=0;
        while(!st.empty()) {
            ans+= st.top();
            st.pop();
        }
        return ans;
    }
};