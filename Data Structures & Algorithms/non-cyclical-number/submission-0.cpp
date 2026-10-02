class Solution {
public:
    int square(int n) {
        vector<int> dig;
        while(n!=0) {
            dig.push_back(n%10);
            cout<<n%10;
            n=n/10;
        }
        int ans = 0;
        for(int i=0;i<dig.size();i++) {
            ans+=dig[i]*dig[i];
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true) {
            int x = square(n);
            
            if(x==1) return true;
            if(st.find(x) != st.end()) return false;
            st.insert(x);
            n=x;
        }
        return false;
    }
};