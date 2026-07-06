class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>> results;
        while(i<intervals.size() && intervals[i][1]<newInterval[0] ) {
            results.push_back(intervals[i]);
            i++;
        }
        int minStart=newInterval[0],maxEnd=newInterval[1];
        while(i<intervals.size() && intervals[i][0] <= newInterval[1] ) {
            minStart = min(minStart,intervals[i][0]);
            maxEnd = max(maxEnd,intervals[i][1]);
            i++;
        }
        results.push_back({minStart,maxEnd});
        while(i<intervals.size()) {
            results.push_back(intervals[i]);
            i++;
        }
        

        return results;
    }
};