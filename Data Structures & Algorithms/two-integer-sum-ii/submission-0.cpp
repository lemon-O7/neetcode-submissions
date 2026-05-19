class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<numbers.size()){
            while(j>0){
                if(numbers[i]+numbers[j]==target) {
                    vector<int> result={i+1,j+1};
                    return result;
                }
                else if(numbers[i]+numbers[j]<target) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
    }
};
