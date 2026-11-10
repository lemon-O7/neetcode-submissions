class Solution {
public:
    bool canSplit(vector<int>& nums, int k,int cap) {
        int curr=nums[0];
        for(int i=1;i<nums.size();i++) {
            curr+=nums[i];
            if(curr>cap) {
                curr=nums[i];
                k--;
            }
        }
        if(k<1) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxelem,sum;
        maxelem = INT_MIN;
        sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(maxelem<nums[i]) {
                maxelem=nums[i];
            }
            sum+=nums[i];
        }
        int lo,hi,mid;
        lo=maxelem;
        hi=sum;
        while(lo<=hi){
            mid = lo +(hi-lo)/2;
            if(canSplit(nums,k,mid)) {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
            
        }
        return ans;
    }
};