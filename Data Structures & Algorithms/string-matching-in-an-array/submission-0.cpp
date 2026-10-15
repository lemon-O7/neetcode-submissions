class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        vector<bool> ex(words.size(),false);
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<words.size();j++) {
                if(i==j) continue;
                if(words[i].find(words[j])!= string::npos && ex[j] == false){ 
                    ans.push_back(words[j]);
                    ex[j] = true;
                }
                else {
                    continue;
                }
            }
        }
        return ans;
    }
};