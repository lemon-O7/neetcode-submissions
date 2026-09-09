class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1,0);
        for(int i=1;i<=n;i++) {
            int temp=i;
            for(int j=0;j<32;j++) {
                if(temp&1 == 1) arr[i]++;
                temp=temp>>1; 
            }
        }
        return arr;
    }
};