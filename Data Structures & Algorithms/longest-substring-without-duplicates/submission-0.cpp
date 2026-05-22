class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j;
        unordered_set<char> substring;
        int ans=0;
        substring.insert(s[i]);
        while(i<s.size()){
            j=i+1;
            if(!substring.count(s[i])){
                substring.insert(s[i]);
            }
            int temp=1;
            while(j<s.size()) {
                if(!substring.count(s[j])){
                    substring.insert(s[j]);
                    temp++;
                    j++;                    
                }
                else {
                    break;
                }
                
            }
            if(temp>ans) {
                ans=temp;
            }
            i++;
            substring.clear();
            
        }
        return ans;
    }
};