class Solution {
public:
    void Merge(vector<int>& nums,vector<int>& B,int l,int mid,int h) {
        int i=l,j=mid+1,k=l;
        
        while(i<=mid && j<=h){
            if(nums[i]<nums[j]) {
                B[k++] = nums[i++];
            }
            else {
                B[k++] = nums[j++];
            }
        }
        for(;i<=mid;i++) {
            B[k++] = nums[i];
        }
        for(;j<=h;j++) {
            B[k++] = nums[j];
        }
        for(i=l;i<=h;i++) {
            nums[i]=B[i];
        }
    }
    void RMerge(vector<int>& nums,vector<int>& B,int l,int h) {
        int mid;
        if(l<h) {
            mid = (l+h)/2;
            RMerge(nums,B,l,mid);
            RMerge(nums,B,mid+1,h);
            Merge(nums,B,l,mid,h);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> B(nums.size());
        RMerge(nums,B,0,nums.size()-1);
        return nums;
    }
};