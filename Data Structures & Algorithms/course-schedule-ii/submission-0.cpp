class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> result;
        for(auto& p : prerequisites) {
            adjlist[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        int count =0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            result.push_back(x);
            count++;

            for(int neighbor : adjlist[x]) {
                indegree[neighbor]--;
                if(indegree[neighbor]==0) {
                    q.push(neighbor);
                }
            }

        }
        if(count == numCourses) {
            return result;
        }
        vector<int> empty;
        return empty;
    }
};