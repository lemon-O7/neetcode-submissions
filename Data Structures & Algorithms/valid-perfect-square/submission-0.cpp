class Solution {
public:
    bool isPerfectSquare(int num) {
       long int l,h,m;
       l=0;
       h=num;
       while(l<=h) {
        m = l + (h-l)/2;
        if(m*m == num) return true;
        else if(m*m < num) l = m+1;
        else h = m-1;
       }
       return false; 
    }
};