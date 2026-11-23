class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top,bot,rig,lef;
        top = 0;
        bot = matrix.size()-1;
        if(matrix.empty()) return ans;
        rig = matrix[0].size()-1;
        lef = 0;
        while(top<=bot && lef<=rig) {
            for(int j=lef;j<=rig;j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top;i<=bot;i++) {
                ans.push_back(matrix[i][rig]);
            }
            rig--;
            if(top<=bot) {
                for(int j=rig;lef<=j;j--) {
                    ans.push_back(matrix[bot][j]);
                }
                bot--;
            }
            if(lef<=rig) {
                for(int i=bot;i>=top;i--) {
                    ans.push_back(matrix[i][lef]);
                }
                lef++;
            }
        }
        return ans;
    }
};