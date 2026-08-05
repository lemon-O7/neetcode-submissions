class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/')) {
            if(token == "" || token == ".") {
                continue;
            }
            else if(token == "..") {
                if(!st.empty()) st.pop_back();
            }
            else {
                st.push_back(token);
            }
        }
        string ans = "/";
        for(int i=0;i<st.size();i++) {
            ans += st[i];
            if(i != st.size()-1) ans += "/";
        }
        return ans;
    }
};