class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        priority_queue<int> heap; 
        queue<pair<int,int>> cooldown;
        int time=0;
        for(int i=0;i<tasks.size();i++) {
            map[tasks[i]]++;
        }
        for(auto& p : map) {
            heap.push(p.second);
        }
        while(!heap.empty() || !cooldown.empty()) {
            time++;
            if(!heap.empty()) {
                int count = heap.top();
                heap.pop();
                count--;
                if(count>0)
                    cooldown.push({count,time+n});
            }
            if(!cooldown.empty() && cooldown.front().second <=time) {
                if(cooldown.front().first >0){    
                    heap.push(cooldown.front().first);
                    }
                cooldown.pop();
            }
        }

        return time;
    }
};