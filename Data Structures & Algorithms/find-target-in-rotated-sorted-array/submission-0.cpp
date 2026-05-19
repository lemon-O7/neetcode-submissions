class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        int mid;
        while(low<high) {
            mid=low + (high-low)/2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(nums[low]==target) {
            return low;
        }

        int low1 = low+1;
        high=nums.size()-1;

        while(low1<=high) {
            mid=low1 + (high-low1)/2;
            if(nums[mid]<target) {
                low1=mid+1;
            }
            else if(nums[mid]>target) {
                high=mid-1;
            }
            else {
                return mid;
            }
        }
        low1 = 0;
        high=low-1;

        while(low1<=high) {
            mid=low1 + (high-low1)/2;
            if(nums[mid]<target) {
                low1=mid+1;
            }
            else if(nums[mid]>target) {
                high=mid-1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};