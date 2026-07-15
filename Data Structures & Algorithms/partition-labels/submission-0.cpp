class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> index;
        int start=0,end=0;
        vector<int> result;
        //tracking index
        for(int i=0;i<s.size();i++) {
            index[s[i]]=i;
        }
        //making parts
        for(int i=0;i<s.size();i++) {
            end = max(end,index[s[i]]);
            if(i==end) {
                result.push_back(end - start + 1);
                start = i+1;
            }
        }
        return result;
    }
};