class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for(int i=n-1;i>=0;i--) {
            if(digits[i]!=9) {
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }
        
        vector<int> ans(n,0);
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};