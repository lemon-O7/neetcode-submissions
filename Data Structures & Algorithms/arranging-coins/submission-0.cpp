class Solution {
public:
    int arrangeCoins(int n) {
        long long l,m,h;
        l=0;
        
        h = n;
        while(l<=h) {
            m = l + (h-l)/2;
            if((m*(m+1))/2<n) l = m+1;
            else if((m*(m+1))/2>n) h = m-1;
            else return m;
        }
        return h;
    }
};