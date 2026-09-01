class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest=INT_MAX;
        int j;
        if(strs.size()==1) return strs[0];
        for(int i=0;i<strs.size();i++) {
            if(shortest>strs[i].size()) {
                j=i;
                shortest=strs[i].size();
            }
        }
        string ans;
        int temp=strs[j].size();
        for(int i=0;i<strs.size();i++) {
            int p=0;
            for(int k=0;k<strs[j].size();k++) {
                if(strs[j][k]==strs[i][k]) {
                    p++;
                }
                else {
                    break;
                }
            }   
            if(temp>p) {
                temp=p;
            }
        }
        for(int i=0;i<temp;i++) {
            ans.push_back(strs[j][i]);
        }
        return ans;
    }
};