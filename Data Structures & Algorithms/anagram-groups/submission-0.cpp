class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strscopy= strs;
        vector<string> anagrams;
        unordered_map<string,vector<string>> groups;
        vector<vector<string>> matrix={};
        for(int i=0;i<strs.size();i++) {
            sort(strs[i].begin(),strs[i].end());
            groups[strs[i]].push_back(strscopy[i]);
        }
        
        for(auto& p : groups) {
            matrix.push_back(p.second);
        }
        
        
        return matrix;
    }
};
