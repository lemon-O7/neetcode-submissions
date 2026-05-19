class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int i=0;
        int j=height.size()-1;
        int temp=0;
        while(i<j){
            
            int h,b;
            h=min(height[i],height[j]); 
            b=j-i;
            result=max(result,h*b);
            if(height[i]<height[j]) {
                i++;
            }
            else if(height[i]>=height[j]) {
                j--;
            }
            
        }
        return result;
    }
};