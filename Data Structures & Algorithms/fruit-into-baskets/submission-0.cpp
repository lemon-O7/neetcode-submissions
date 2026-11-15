class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l,r;
        l=r=0;
        int ans = 0;
        unordered_map<int,int> freq;
        for(;r<fruits.size();r++) {
            freq[fruits[r]]++;
            while(freq.size()>2) {
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0) freq.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};