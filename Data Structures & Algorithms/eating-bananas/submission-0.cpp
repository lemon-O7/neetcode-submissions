class Solution {
public:
    int max(vector<int>& piles) {
        int x=0;
        for(int i=0;i<piles.size();i++) {
            if(x<piles[i]){
                x=piles[i];
            }
        }
        return x;
    }

    long long hours(vector<int>& piles,int k) {
        long long hours=0;
        for(int i=0;i<piles.size();i++) {
            hours+=((long long) piles[i] + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1,high=max(piles);
    
        int mid=low + (high-low)/2;
        int k=high;
        while(low<=high) {
            mid=low + (high-low)/2;

            if(hours(piles,mid) <= h) {
            k = mid;        // possible answer
            high = mid - 1;  // try smaller speed
            }
            else {
            low = mid + 1;   // need faster speed
            }
        }


        return k;
    }
};