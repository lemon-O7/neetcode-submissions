class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        while(b!=0) {
            int xorsum = a^b;
            int carry = (static_cast<unsigned int>(a&b) << 1);
            a=xorsum;
            b=carry;
        }
        return a;
    }
};