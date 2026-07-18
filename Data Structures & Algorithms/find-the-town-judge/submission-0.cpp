class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> freq;
        if(n == 1 && trust.empty()) return 1;
        for(int i=0;i<trust.size();i++) {
            freq[trust[i][1]]++;
        }
        int maxtrust=0,judge=1;

        for(auto& [p,q]: freq) {
            if(maxtrust<q) {
                maxtrust = q;
                judge = p;
            }
        }
        
        for(int i=0;i<trust.size();i++) {
            if(trust[i][0]==judge) {
                return -1;
            }
        }
        if(freq[judge]==n-1) {
            
            return judge;
        }
        return -1;
    }
};