class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd,minProd,res;
        maxProd=minProd=res=nums[0];
        for(int i=1;i<n;i++) {
            int a = maxProd * nums[i];
            int b = minProd * nums[i];
            int c = nums[i];

            maxProd = max({a,b,c});
            minProd = min({a,b,c});
            res = max(maxProd,res);
        }
        return res;
    }
};