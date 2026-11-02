class Solution {
public:
    string clearDigits(string s) {
        for(int i=0;i<s.size();i++) {
            if(s[i]>47 && s[i]<58) {
                s.erase(s.begin()+i);
                int x=i-1;
                bool flag = false;
                while(-1<x && !flag) {
                    if(s[x]>=58 || s[x]<=47) {
                        s.erase(s.begin()+x);
                        flag = true;
                    }
                    x--;
                }
                i-=2;
            }
            
        }
        return s;
    }
};