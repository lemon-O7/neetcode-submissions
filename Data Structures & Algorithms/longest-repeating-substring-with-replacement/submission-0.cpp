class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;

        unordered_map<char,int> freqmap;
        int ans=0;
        int maxfreq=1;

        while(right<s.size()) {
            int temp;
            freqmap[s[right]]++;
            temp = freqmap[s[right]];
            if(maxfreq<temp) {
                maxfreq=temp;
            }
            while((right-left+1)-maxfreq>k) { 
                freqmap[s[left]]--;
                left++;
            }
            right++;
            ans=max(ans, (right-left));
        }

        return ans;
    }
};
