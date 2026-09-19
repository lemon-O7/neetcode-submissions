class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x,xx =x;
        n--;
        int pos=0;
        while(n!=0) {
            if(((xx>>pos)&1) == 0) {
                if((n&1) == 1) {
                    ans |= (1LL<<pos); 
                }
                n>>=1;
            }
            pos++;
        }
        return ans;
    }
};