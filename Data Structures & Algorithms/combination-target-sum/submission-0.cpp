class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void recur(vector<int>& candidates, int target, int i, int cursum) {
        if(i==candidates.size()) return ;
        if(cursum > target) return ;
        if(target == cursum) {
            ans.push_back(cur);
            return ;
        }
        recur(candidates,target,i+1,cursum);
        cur.push_back(candidates[i]);
        recur(candidates,target,i,cursum+candidates[i]);
        cur.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recur(candidates,target,0,0);
        return ans;
    }
};