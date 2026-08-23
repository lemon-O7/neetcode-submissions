class Solution {
public:
    vector<int> arr = vector<int>(40, -1);

    int tribonacci(int n) {
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        if(arr[n]!=-1) {
            return arr[n];
        }

        arr[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        
        return arr[n];    
    }
};