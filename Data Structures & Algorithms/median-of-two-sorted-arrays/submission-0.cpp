class Solution {
public:
    double BinSearch(vector<int>& smallnums,vector<int>& bignums) {
        int n=smallnums.size();
        int m=bignums.size();
        int low=0;
        int high=smallnums.size();
        int left = (n+m+1)/2;
        double result;
        while(low<=high) {
            int i= (low+high)/2;
            int j=  left-i;
            int Aleft = (i == 0) ? INT_MIN : smallnums[i-1]; 
            int Aright = (i == n) ? INT_MAX : smallnums[i]; 
            int Bleft = (j == 0) ? INT_MIN : bignums[j-1]; 
            int Bright = (j == m) ? INT_MAX : bignums[j];
            if(Aleft<=Bright && Bleft<=Aright) {
                if((n+m)%2!=0) {
                    return max(Aleft,Bleft);
                }                
                else {
                    return (max(Aleft,Bleft)+min(Aright,Bright))/2.0;
                }
            }
            else if(Aleft>Bright) {
                high=i-1;
            }
            else {
                low=i+1;
            }
        }

        return result;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int Aleft,Aright,Bleft,Bright;
        double ans;
        if(nums1.size()<nums2.size()) {
            ans=BinSearch(nums1,nums2);
        }
        else {
            ans=BinSearch(nums2,nums1);
        }

        
        return ans;
    }
};