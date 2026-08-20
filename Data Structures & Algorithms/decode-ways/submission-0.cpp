class Solution {
public:
    vector<int> memo;
    int DFS(string s,int i) {
        if(i>=s.size() ) {
            return 1;
        }
        if(memo[i]!=-1) {
            return memo[i];
        }
        if(s[i]=='0') {
            return 0;
        }
        if(i + 1 < s.size()) {
            if((s[i]-'0')*10 + (s[i+1]-'0') <= 26) {
                memo[i] = DFS(s,i+1) + DFS(s,i+2);
                return memo[i];
            }
        }
        memo[i]=DFS(s,i+1);
        return memo[i];
    }
    int numDecodings(string s) {
        memo.assign(s.size()+1,-1);
        
        return DFS(s,0);
    }
};