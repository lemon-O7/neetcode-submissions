class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> rank;
        for(int i=0;i<order.size();i++) {
            rank[order[i]]=i;
        }

        for(int i=0;i+1<words.size();i++) {
            bool flag=false;
            for(int j=0;j<min(words[i].size(),words[i+1].size());j++) {
                if(rank[words[i][j]]<rank[words[i+1][j]]) {
                    flag = true;
                    break;
                }
                if(rank[words[i][j]]>rank[words[i+1][j]]) {
                    return false;
                }
                
            }
            if(words[i].size()>words[i+1].size() && flag == false) {
                        return false;
            }
        }
        return true;

    }
};