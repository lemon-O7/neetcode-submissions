class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=(matrix.size()*matrix[low].size())-1;
        

        while(low<=high){
        int mid=low+((high-low)/2);
        int x,y;
        x=mid/matrix[0].size();
        y=mid%matrix[0].size();
        
        if(matrix[x][y]<target){
            low=mid+1;
        }
        else if(matrix[x][y]>target){
            high=mid-1;
        }
        else {
            return true;
        }
        }

        return false;
    }
};