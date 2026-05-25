class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> T;
        unordered_map<char,int> window;

        for(char c : t) {
            T[c]++;
        }
        int have = 0;
        int need = T.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right=0;right<s.size();right++) {
            char c = s[right];
            window[c]++;

            if(T.count(c) && window[c] == T[c]) {
                have++;
            }

            while(have == need) {

                if((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if(T.count(s[left]) &&
                   window[s[left]] < T[s[left]]) {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};