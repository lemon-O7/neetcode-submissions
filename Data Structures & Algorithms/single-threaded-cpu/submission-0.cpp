class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        for(int i=0;i<tasks.size();i++) {
            tasks[i].push_back(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        sort(tasks.begin(),tasks.end());
        long long int curtime=0;
        int i=0;
        int n=tasks.size();
        while(ans.size()!=n) {
            
            if(heap.empty() && tasks[i][0]>curtime) {
                curtime = tasks[i][0];
            }
            while(i<n && tasks[i][0]<=curtime) {
                heap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            pair<int,int> temp = heap.top();
            heap.pop();
            ans.push_back(temp.second);
            curtime+=temp.first;
        }
        return ans;
    }
};