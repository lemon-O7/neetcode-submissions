class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int temp=0;
        for(int i=0;i<32;i++) {
            if(left == right) break;
            left>>=1;
            right>>=1;
            temp++;
        }
        for(int i=0;i<temp;i++) {
            left<<=1;
        }
        
        return left;
    }
};