class Solution {
public:
    bool possible(vector<int>& weights,int days,int x) {
        int need =1;
        int cur = 0;
        for(int i=0;i<weights.size();i++) {
            if(cur + weights[i] >x) {
                need++;
                cur = 0;
            }
            cur += weights[i];
        }
        return need <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min = INT_MIN,max = 0;
        for(int i=0;i<weights.size();i++) {
            if(min < weights[i]) {
                min = weights[i];
            }
            max += weights[i];
        }
        int mid;
        int ans = max;
        while(min <= max) {
            
            mid = min + ((max-min)/2);
            if(possible(weights,days,mid)) {
                ans=mid;
                max=mid-1;
            }
            else {
                min=mid+1;
            }
        }
        return ans;
    }
};