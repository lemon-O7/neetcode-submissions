class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans=0;
        unordered_map<char,int> map;
        for(int i=0;i<text.size();i++) {
            map[text[i]]++;
        }
        while(map['b']>=1 && map['a']>=1 && map['l']>=2 && map['o']>=2 && map['n']>=1) {
            map['b']-=1; map['a']-=1; map['l']-=2; map['o']-=2; map['n']-=1;
            ans++;
        }
        return ans;
    }
};