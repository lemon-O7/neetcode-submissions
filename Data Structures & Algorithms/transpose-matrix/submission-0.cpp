class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int n = matrix.size(),m=matrix[0].size();
        ans.assign(m,vector<int>(n,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};