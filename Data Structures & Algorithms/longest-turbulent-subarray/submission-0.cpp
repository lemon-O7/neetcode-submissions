class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr=1;
        int i,prevsign,ans;
        ans=1;
        prevsign=0;
        for(i=1;i<arr.size();i++) {
            
            if(arr[i]>arr[i-1]) {
                curr = (prevsign == 1) ? curr+1 : 2;
                prevsign = -1;
            }
            else if(arr[i]<arr[i-1]) {
                curr = (prevsign == -1) ? curr+1 : 2;
                prevsign = 1;
            }
            else {
                curr = 1;
                prevsign=0;
            }
            ans = max(curr,ans);
        }
        
        return ans;
    }
};