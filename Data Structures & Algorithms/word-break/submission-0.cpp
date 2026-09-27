class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> arr(s.size()+1,false);
        arr[s.size()] = true;
        unordered_set<string> Dict;
        for(int i=0;i<wordDict.size();i++) {
            Dict.insert(wordDict[i]);
        }
        for(int i=s.size()-1;i>=0;i--) {
            for(auto& x : Dict) {
                if(s.substr(i, x.size()) == x) {
                    if(i+x.size()<arr.size() && arr[i+x.size()]) {
                        arr[i] = true;
                        break;
                    }
                }
            }
        }
        return arr[0];
    }
};