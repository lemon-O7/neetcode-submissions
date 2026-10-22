class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(1,1);
        int i2,i3,i5;
        i2=i3=i5=0;
        while(nums.size()<n) {
            int a,b,c;
            a = nums[i2] *2;
            b = nums[i3] *3;
            c = nums[i5] *5;
            int MinCandi = min({a,b,c});
            if(MinCandi == a) i2++;
            if(MinCandi == b) i3++;
            if(MinCandi == c) i5++;
            nums.push_back(MinCandi);
        }
        return nums[n-1];
    }
};