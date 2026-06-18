class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        int maxright,maxleft;
        maxright=maxleft=0;
        while(right>=left) {
            if(maxleft <= maxright) {
                maxleft = max(maxleft, height[left]);
                
                ans += max(0, min(maxleft, maxright) - height[left]);
                left++;
            }
            else {
                maxright = max(maxright, height[right]);
                
                ans += max(0, min(maxleft, maxright) - height[right]);
                right--;
            
            }
        }

        return ans;

    }
};