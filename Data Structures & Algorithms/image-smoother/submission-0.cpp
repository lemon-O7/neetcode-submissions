class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(),vector<int>(img[0].size(),-1));
        for(int i=0;i<img.size();i++) {
            for(int j=0;j<img[0].size();j++) {
                int tsum=0,f=1;
                tsum+=img[i][j];
                if(i+1<img.size()) {
                    tsum+=img[i+1][j];
                    f++;
                }
                if(j+1<img[i].size()) {
                    tsum+=img[i][j+1];
                    f++;
                }
                if(0<=i-1) {
                    tsum+=img[i-1][j];
                    f++;
                }
                if(0<=j-1) {
                    tsum+=img[i][j-1];
                    f++;
                }
                if(i+1<img.size() && j+1<img[i].size()) {
                    tsum+=img[i+1][j+1];
                    f++;
                }
                if(j+1<img[i].size() && 0<=i-1) {
                    tsum+=img[i-1][j+1];
                    f++;
                }
                if(0<=j-1 && 0<=i-1) {
                    tsum+=img[i-1][j-1];
                    f++;
                }
                if(i+1<img.size() && 0<=j-1) {
                    tsum+=img[i+1][j-1];
                    f++;
                }
                res[i][j] = floor(tsum/f);
            }
        }
        return res;
    }
};