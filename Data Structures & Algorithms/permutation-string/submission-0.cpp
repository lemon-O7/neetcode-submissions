class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        vector<int> window(26,0);
        int left =0;
        if(s1.size()>s2.size()) {
            return 0;
        }
        for(int i = 0; i < s1.size(); i++) {
            window[s2[i] - 'a']++;
        }
        int right;
        
        for(int i=0;i<s1.size();i++) {
            freq[s1[i] - 'a']++;
        }
        right = s1.size();
        while(right<s2.size()) {
           if(freq==window) {
            return 1;
           }
           else {
            window[s2[right] - 'a']++;
            window[s2[left] - 'a']--;
           }
        left++;
        right++;
        }
       
        if(freq == window) {
            return true;
        }
        return false;
        
    }
};