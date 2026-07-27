class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p,q;
        p=q=0;
        string ans;

        while(word1[p]!=NULL && word2[q]!=NULL) {
            ans.push_back(word1[p]);
            ans.push_back(word2[q]);
            p++;
            q++;
        }

        while(word1[p]!=NULL) {
            ans.push_back(word1[p]);
            p++;
        }

        while(word2[q]!=NULL) {
            ans.push_back(word2[q]);
            q++;
        }

        return ans;
    }
};