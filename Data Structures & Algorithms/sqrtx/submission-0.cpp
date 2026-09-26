class Solution {
public:
    int mySqrt(int x) {
        int h,l;
        long long mid;
        l=0;
        h=x;
        while(l<=h) {
            mid = l+ (h-l)/2;
            if(mid*mid == x) return mid;
            if(mid*mid < x) l = mid+1;
            if(mid*mid > x) h = mid-1;
        }
        return h;
    }
};