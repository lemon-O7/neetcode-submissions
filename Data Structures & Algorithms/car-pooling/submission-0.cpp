class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        int count=0;
        sort(trips.begin(),trips.end(), [](const vector<int>& a,const vector<int>& b) {return a[1]<b[1];});
        for(int i=0;i<trips.size();i++) {
            
            while(!heap.empty() && trips[i][1]>= heap.top().first) {
                count -= heap.top().second;
                heap.pop();
            }
            count+= trips[i][0];
            if(count>capacity) return false;
            heap.push({trips[i][2],trips[i][0]});
        }
        return true;
    }
};