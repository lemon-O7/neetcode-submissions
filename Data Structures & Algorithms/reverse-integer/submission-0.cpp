class Solution {
public:
    int reverse(int x) {
        int res,MAX,MIN;
        res=0;
        MAX=INT_MAX;
        MIN=INT_MIN;

        while(x != 0) {
            if(res>MAX/10) return 0;
            if(res<MIN/10) return 0;
            if(res == MAX/10 && x%10 > MAX%10) return 0;
            if(res == MIN/10 && x%10 < MIN%10) return 0;
            res = res*10 + x%10;
            x=x/10;
        }
        return res;
    }
};